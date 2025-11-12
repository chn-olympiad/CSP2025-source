#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
        int a1=0,b1=0,c1=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&b[i]>=c[i]){
				if(a1<n/2)
				    a1++,ans+=a[i];
				else if(b1<n/2)
				    b1++,ans+=b[i];
				else
				    c1++,ans+=c[i];
			}
			else if(a[i]>=c[i]&&c[i]>=b[i]){
				if(a1<n/2)
				    a1++,ans+=a[i];
				else if(c1<n/2)
				    c1++,ans+=c[i];
				else
				    b1++,ans+=b[i];
			}
			else if(b[i]>=a[i]&&a[i]>=c[i]){
				if(b1<n/2)
				    b1++,ans+=b[i];
				else if(a1<n/2)
				    a1++,ans+=a[i];
				else
				    c1++,ans+=c[i];
			}
			else if(b[i]>=c[i]&&c[i]>=a[i]){
				if(b1<n/2)
				    b1++,ans+=b[i];
				else if(c1<n/2)
				    c1++,ans+=c[i];
				else
				    a1++,ans+=a[i];
			}
			else if(c[i]>=a[i]&&a[i]>=b[i]){
				if(c1<n/2)
				    c1++,ans+=c[i];
				else if(a1<n/2)
				    a1++,ans+=a[i];
				else
				    b1++,ans+=b[i];
			}
			else if(c[i]>=b[i]&&b[i]>=a[i]){
				if(c1<n/2)
				    c1++,ans+=c[i];
				else if(b1<n/2)
				    b1++,ans+=b[i];
				else
				    a1++,ans+=a[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
