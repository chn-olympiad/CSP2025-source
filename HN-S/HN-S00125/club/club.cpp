#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define int long long
int a[N],b[N],c[N],d[N],e[N],f[N];
int x[5],o[10],v=0;
int t;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		int n,ans=0,w=0,g;
		for(int i=1;i<=3;i++){
			x[i]=0;
		}
		for(int i=1;i<=N;i++){
			d[i]=f[i]=e[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(c[i]>=a[i]&&c[i]>=b[i]){
				ans+=c[i];
				x[3]++;
				d[i]=min(c[i]-a[i],c[i]-b[i]);
				continue;
			}
			if(b[i]>=a[i]&&b[i]>=c[i]){
				ans+=b[i];
				x[2]++;
				e[i]=min(b[i]-a[i],b[i]-c[i]);
				continue;
			}
			if(a[i]>=c[i]&&a[i]>=b[i]){
				ans+=a[i];
				x[1]++;
				f[i]=min(a[i]-c[i],a[i]-b[i]);
				continue;
			}
		}
		for(int i=1;i<=3;i++){
			if(x[i]*2>n){
				w=1;
				g=i;
				break;
			}
		}
		if(w==0){
			o[v]=ans;
			v++;
		}else{
			if(g==1){
				sort(f+1,f+n+1);
				int q=x[g]-n/2,l=0;
				for(int i=1;i<=n;i++){
					if(f[i]!=0){
						ans-=f[i];
						l++;
					}
					if(l==q){
						break;
					}
				}
			}
			if(g==2){
				sort(e+1,e+n+1);
				int q=x[g]-n/2,l=0;
				for(int i=1;i<=n;i++){
					if(e[i]!=0){
						ans-=e[i];
						l++;
					}
					if(l==q){
						break;
					}
				}
			}
			if(g==3){
				sort(d+1,d+n+1);
				int q=x[g]-n/2,l=0;
				for(int i=1;i<=n;i++){
					if(d[i]!=0){
						ans-=d[i];
						l++;
					}
					if(l==q){
						break;
					}
				}
			}
			o[v]=ans;
			v++;
		}
	}
	for(int i=0;i<v;i++){
		cout<<o[i]<<endl;
	}
	return 0;
}
