#include<bits/stdc++.h>
using namespace std;
int T,n,a[100000],b[100000],c[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		memset(a,0,sizeof(a));
		cin>>n;
		int len=n/2,a1=0,b1=0,c1=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]&&a1!=len){
				ans+=a[i];
				a1++;
			}
			if(b[i]>=a[i]&&b[i]>=c[i]&&b1!=len){
				ans+=b[i];
				b1++;
			}
			if(c[i]>=a[i]&&c[i]>=b[i]&&c1!=len){
				ans+=c[i];
				c1++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
