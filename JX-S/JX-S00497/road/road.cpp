#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1000;
long long n,m,k,fa[N],cnt,ans,ls[N],lcnt;
struct stu{
	long long x,y,z;
}a[N];
long long find(long long x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool cmp(stu aa,stu bb){
	return aa.z<bb.z;
}
void f(){
	for(int i=1;i<=m;i++){
		long long xx=find(a[i].x),yy=find(a[i].y);
		if(xx!=yy){
			if(!ls[xx]&&xx<=n){
				ls[xx]=1;
				lcnt++;
			}
			if(!ls[yy]&&yy<=n){
				ls[yy]=1;
				lcnt++;
			}
			fa[xx]=yy;
			cnt++;
			ans+=a[i].z;
		}
		if(lcnt==n)return;
		//if(cnt==n-1)return;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);//lld
	}
	for(int i=1;i<=k;i++){
		long long xxx;
		scanf("%lld",&xxx);
		for(int j=1;j<=n;j++){
			scanf("%lld",&xxx);
			a[++m].x=n+i;
			a[m].y=j;
			a[m].z=xxx;
		}
	}
	sort(a+1,a+m+1,cmp);
	f();
	cout<<ans;
	return 0;
}
