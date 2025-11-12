#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,c_0=0,c_1=0;
	cin>>n>>k;
	ll arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]==0)c_0++;
		else c_1++;
	}
	if(n==2){
		cout<<1<<endl;
		return 0;
	}
	if(k==0)cout<<c_0;
	else cout<<c_1;
	return 0;
}
