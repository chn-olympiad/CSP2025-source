#include<iostream>
#include<algorithm>
using namespace std;
struct Pe{
	int jin,ndv,mx;
	int v[4];
	void chg(){
		for(int i=1;i<=3;i++){
			if(i==jin) continue;
			ndv=max(ndv,v[i]);
		}
		ndv-=mx;
	}
}a[112345];
int cmp(Pe a,Pe b){
	return a.ndv>b.ndv; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0,clp[4]={0,0,0,0};
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i].jin=0,a[i].ndv=0;
			int in=1;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i].v[j]);
				if(a[i].v[j]>a[i].v[in]){
					in=j;
				}
			}
			a[i].jin=in;
			a[i].mx=a[i].v[in];
			a[i].chg();
			clp[in]++;
			ans+=a[i].v[in];
		}
		int mxn=0;
		for(int i=1;i<=3;i++){
			if(clp[i]>clp[mxn]) mxn=i;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=clp[mxn],j=1;i*2>n;j++){
			if(a[j].jin==mxn){
				i--;
				ans+=a[j].ndv;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
