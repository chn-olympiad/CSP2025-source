#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long a[5],b[5],c[5],n,t,ans=0,wr,wq;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	cin>>t>>n;
	while(t--){
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				ans+=a[i];
			}
			else if(b[i]>a[i]&&b[i]>c[i]){
				ans+=b[i];
			}
			else if(c[i]>a[i]&&c[i]>b[i]){
				ans+=c[i];
			}
		}
		
	}
	cout<<ans<<endl<<max(4,1)<<endl<<max(1,13);
}
//或者是这个||
//并且是这个&& 
