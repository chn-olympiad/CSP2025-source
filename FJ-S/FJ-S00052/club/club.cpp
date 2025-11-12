#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int n;
int a[maxn],b[maxn],c[maxn];
int t;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;int tmpa=0,tmpb=0,tmpc=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				tmpa++,ans+=a[i];
			}else if(b[i]>=c[i]&&b[i]>=a[i]){
				tmpb++,ans+=b[i];
			}else if(c[i]>=b[i]&&c[i]>=a[i]){
				tmpc++,ans+=c[i];
			}
		}
		if(tmpa<=n/2&&tmpb<=n/2&&tmpc<=n/2){
			cout<<ans<<endl;
			continue;
		}
		if(tmpa>n/2){
			int d[maxn],cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]>=b[i]&&a[i]>=c[i]){
					d[++cnt]=max(b[i]-a[i],c[i]-a[i]);
				}
			}
			sort(d+1,d+1+cnt);
			for(int i=tmpa;i>n/2;i--) ans+=d[i];
		}
		else if(tmpb>n/2){
			int d[maxn],cnt=0;
			for(int i=1;i<=n;i++){
				if(b[i]>=a[i]&&b[i]>=c[i]){
					d[++cnt]=max(a[i]-b[i],c[i]-b[i]);
				}
			}
			sort(d+1,d+1+cnt);
			for(int i=tmpb;i>n/2;i--) ans+=d[i];
		}else if(tmpc>n/2){
			int d[maxn],cnt=0;
			for(int i=1;i<=n;i++){
				if(c[i]>=b[i]&&c[i]>=a[i]){
					d[++cnt]=max(b[i]-c[i],a[i]-c[i]);
				}
			}
			sort(d+1,d+1+cnt);
			for(int i=tmpc;i>n/2;i--) ans+=d[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
