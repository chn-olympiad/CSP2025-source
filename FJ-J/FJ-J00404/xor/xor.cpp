#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[500001];
ll su[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		su[i]=su[i-1]^arr[i];
	}
	int le=0;
	for(int i=1;i<=n;i++){
		for(int j=le;j<i;j++){
			if((su[i]^su[j])==k){
				ans++;
				le=i;
				//cout<<j<<" "<<i<<" "<<su[i]<<" "<<su[j]<<" ";
				//cout<<(su[i]^su[j])<<endl;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
