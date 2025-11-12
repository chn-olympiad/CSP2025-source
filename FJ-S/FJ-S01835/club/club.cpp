#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int t,n,a[N],b[N],c[N],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		int a1=0,b1=0,c1=0;
		for(int j=1;j<=n;j++){
			if(a1==n/2){
				if(b[j]>=c[j]){
					b1++;
					ans+=b[j];
				}else if(b[j]<c[j]){
					c1++;
					ans+=c[j];
				}
			}else if(b1==n/2){
				if(a[j]>=c[j]){
					a1++;
					ans+=a[j];
				}else if(c[j]>a[j]){
					c1++;
					ans+=c[j];
				}
			}else if(c1==n/2){
				if(a[j]>=b[j]){
					a1++;
					ans+=a[j];
				}else if(a[j]<b[j]){
					b1++;
					ans+=b[j];
				}
			}else{
				if(a[j]>=b[j]&&a[j]>=c[j]){
					a1++;
					ans+=a[j];
				}else if(b[j]>a[j]&&b[j]>c[j]){
					b1++;
					ans+=b[j];
				}else if(c[j]>a[j]&&c[j]>b[j]){
					c1++;
					ans+=c[j];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
