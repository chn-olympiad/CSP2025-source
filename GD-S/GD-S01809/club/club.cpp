#include<bits/stdc++.h>
using namespace std;
struct club{
	long long a[4];
};
club c[20005];
int nm(int x,int y,int z){
	if(x>y&&x<z||x>z&&x<y){
		return x;
	}
	if(y>x&&y<z||y>z&&y<x){
		return y;
	}
	if(z>x&&z<y||z>y&&z<x){
		return z;
	}
}
long long t;
bool cmp(club x,club y){
	int maxx1=max(max(x.a[1],x.a[2]),x.a[3]);
	int maxx2=max(max(y.a[1],y.a[2]),y.a[3]);
	return maxx1>maxx2;
}
int main(){	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		long long n,ans[4]={},ans1=0,w[4]={};
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>c[i].a[j];
			}
		}
		sort(c+1,c+n+1,cmp);
		int flag=1;
		for(long long i=1;i<=n;i++){
			w[1]=max(max(c[i].a[1],c[i].a[2]),c[i].a[3]);
			w[2]=nm(c[i].a[1],c[i].a[2],c[i].a[3]);
			w[3]=min(min(c[i].a[1],c[i].a[2]),c[i].a[3]);
			for(int k=1;k<=3;k++){
				for(int j=1;j<=3;j++){
					if(w[k]==c[i].a[j]&&ans[j]<(n/2)){
						ans[j]++;
						ans1+=w[k];
						flag=0;
						break;
					}
				}
				if(flag==0){
					break;
				}
			}
		}
		cout<<ans1<<endl;
		ans1=0;
	}
	return 0;
}
