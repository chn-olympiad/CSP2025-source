#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k,Num[15][10005],cnt,father[20005],ans;
struct node{
	int x,y,sum;
	bool operator<(const node &w)const{return sum<w.sum;}
}a[1500005],b[1500005];
int find(int x){return father[x]==x?x:father[x]=find(father[x]);}
void init(){
	for(int i=1;i<=n+k;i++) father[i]=i;
}
void solve(int X){
	int w=n,Cnt=cnt,sum=0;
	for(int i=1;i<=cnt;i++) a[i]=b[i];
	for(int i=0;i<k;i++)
		if((X>>i)&1){
			++w,sum+=Num[i][0];
			for(int j=1;j<=n;j++)
				a[++Cnt]={w,j,Num[i][j]};
		}
	sort(a+1,a+Cnt+1),init();
	for(int i=1;i<=Cnt;i++){
		int x=find(a[i].x),y=find(a[i].y);
		if(x==y) continue;
		sum+=a[i].sum,father[x]=y;
	}
	ans=min(ans,sum);	
}
signed main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].sum);
	sort(a+1,a+m+1),init();
	for(int i=1;i<=m;i++){
		int x=find(a[i].x),y=find(a[i].y);
		if(x==y) continue;
		ans+=a[i].sum,father[x]=y,b[++cnt]=a[i];
	}
	for(int i=0;i<k;i++)
		for(int j=0;j<=n;j++)
			scanf("%lld",&Num[i][j]);
	for(int i=0;i<(1<<k);i++) solve(i);
	return printf("%lld\n",ans),0;
}
