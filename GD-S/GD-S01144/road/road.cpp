#include <bits/stdc++.h>
using namespace std;
int Inf=1000000009;
long long w=0;
int n,m,k,t[1003][1003],cs[1003],v[15];
int cnt=0;
int zu[1003];
long long ans=0;
struct dd{
	int r,l;
	int vv;
}ba[1000005];
bool cmp(dd const &x1,dd const &y1){
	if(x1.vv<y1.vv){
		return true;
	}
	else{
		return false;
	}
}
int f(int x){
	if(zu[x]==x){
		return x;
	}
	else{
		return zu[x]=f(zu[x]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			t[j][i]=Inf;
			t[i][j]=Inf;
		}
	}
	for(int i=1,a,b,v;i<=m;i++){
		scanf("%d%d%d",&a,&b,&v);
		if(a==b){
			continue;
		}
		if(t[a][b]>v){
			t[a][b]=v;
			t[b][a]=v;
		}
	}
	for(int i=1,c;i<=k;i++){
		scanf("%d",&v[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&cs[j]);
		}
		for(int j=1;j<=n;j++){
			for(int j1=j+1;j1<=n;j1++){
				w=cs[j]+cs[j1];
				if(t[j][j1]>w){
					t[j][j1]=w;
				}
			}
		}
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=n;j++){
	//		printf("%d ",t[i][j]);
	//	}
	//	printf("\n");
	//}
	cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt++;
			ba[cnt].l=i;
			ba[cnt].r=j;
			ba[cnt].vv=t[i][j];
			//	printf("%d %d %d %d \n",cnt,ba[cnt].l,ba[cnt].r,ba[cnt].vv);
		}
	}
	sort(ba+1,ba+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
	//	printf("%d %d %d %d \n",cnt,ba[i].l,ba[i].r,ba[i].vv);
	}
	for(int i=1;i<=n;i++){
		zu[i]=i;
	}
	for(int i=1,l1,r1,v1;i<=cnt;i++){
		l1=ba[i].l;
		r1=ba[i].r;
		v1=ba[i].vv;
		if(f(l1)==f(r1)){
			continue;
		}
		else{
			zu[zu[l1]]=f(r1);
			ans=ans+v1;
		//	printf("%d %d %d ",&l1,&r1,&v1);
		}
	}
	for(int i=1;i<=k;i++){
		ans=ans+v[i];
	}
	printf("%lld",ans);
	
	
	return 0;
}
