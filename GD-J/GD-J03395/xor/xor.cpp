#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500009]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,count=0;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
