#include<bits/stdc++.h>
using namespace std;

int t,n,a[5],b[5],c[5],ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i]; 
		}
		sort(a+1,a+1+n);
		for(int i=n;i>n/2;i--){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
