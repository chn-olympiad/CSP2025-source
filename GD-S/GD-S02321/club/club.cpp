#include<bits/stdc++.h>
using namespace std;
#define ll long long
short t,s[5];
ll n,ans,c1,c2;
ll a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,c1=0,c2=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			ll x,y,z;
			cin>>x>>y>>z;
			ans+=x;
			a[i]=y-x;
		}
		sort(a+1,a+n+1);
		for(int i=n;i>n/2;i--){
//			cout<<"  "<<a[i];
			ans+=a[i];
//			cout<<"  "<<i;
//			cout<<endl;
		}
//		cout<<endl;
		cout<<ans<<endl;
//		" "<<n-c1-c2<<" "<<c1<<" "<<c2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
