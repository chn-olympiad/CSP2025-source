#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005],b[100005],c[100005];
int ans,x,y,z;
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int value=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		//for(int i=0;i<=n;i++){
		for(int j=n;j>=1;j--){
			if(a[j]>b[j]&&a[j]>=c[j]){
				ans+=a[j];
				//cout<<a[j]<<" "<<x<<" "<<"1"<<endl;
				x++; 
			}
			if(b[j]>a[j]&&b[j]>=c[j]){
				ans+=b[j];
				//cout<<b[j]<<" "<<y<<" "<<"2"<<endl;
				y++; 
			}
			if(c[j]>b[j]&&c[j]>=a[j]){
				ans+=c[j];
				//cout<<c[j]<<" "<<z<<" "<<"3"<<endl;
				z++;
			}
			if(x>=value){
				for(int i=1;i<=n;i++){
					a[i]=0;
				}
			}
			if(y>=value){
				for(int i=1;i<=n;i++){
					b[i]=0;
				}
			}
			if(z>=value){
				for(int i=1;i<=n;i++){
					c[i]=0;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
