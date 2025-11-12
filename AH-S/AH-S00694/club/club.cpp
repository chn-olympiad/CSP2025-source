#include<bits/stdc++.h>
using namespace std;
int ans,az,bz,cz;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		az=0;
		bz=0;
		cz=0;
		ans=0;
		int a[100005],b[100005],c[100005];
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		for(int j=1;j<=n;j++){
			if(a[j]>=max(b[j],c[j])){
				if(az*2<n){
					az++;
				ans+=a[j];
				}
				else {
				int bj=10000000;
					for(int k=1;k<=j;k++){
					int sz=a[k]-max(b[k],c[k]);
						bj=min(bj,sz);
					}
					int mq=a[j]-max(b[j],c[j]);
					if(mq>bj) ans=ans+a[j]-bj;
					else {
						ans+=max(b[j],c[j]);
					}
				}
			}
			else if(b[j]>=max(a[j],c[j])){
				if(bz*2<n){
					
					bz++;
				ans+=b[j];
				}
				else {
				int bj=10000000;
					for(int k=1;k<=j;k++){
					int sz=b[k]-max(a[k],c[k]);
						bj=min(bj,sz);
					}
					int mq=b[j]-max(a[j],c[j]);
					if(mq>bj) ans+=b[j]-bj;
					else {
						ans=ans+max(a[j],c[j]);
					}
				}
			}
			else if(c[j]>=max(a[j],b[j])){
				if(cz*2<n){
					cz++;
				ans+=c[j];
				}
				else {
				int bj=10000000;
					for(int k=1;k<=j;k++){
					int sz=c[k]-max(b[k],a[k]);
						bj=min(bj,sz);
					}
					int mq=c[j]-max(b[j],a[j]);
					if(mq>bj) ans=ans+c[j]-bj;
					else {
						ans=ans+max(b[j],a[j]);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
