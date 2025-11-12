#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;

ll n,k,la,sum,ans;
ll a[N],mp[N];

void read(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
}
void solve(){
	for(int i=1;i<=n;i++){
		sum^=a[i];
//		cout<<sum<<" "<<la<<" ";/*<<sum^k<<" ";*/
		if(mp[sum^k]>la||sum==k){
			la=i;
//			cout<<ans<<"-"; 
			ans++;
//			cout<<ans<<"\n";
			sum=0; 
		}
		mp[0]=mp[sum]=i; 
//		cout<<ans<<"\n";
	}
	cout<<ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ont","w",stdout);
	read();solve();
	return 0;
}