#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[600000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,sum=0,zan=-1;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(zan==-1){
			zan=a[i];
		}
		else{
			zan=(zan)xor(a[i]);
		}
		if(zan==k or a[i]==k){
			sum++;
			zan=-1;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
