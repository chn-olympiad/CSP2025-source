#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500010],n,k,ans=0;
ll check(ll l,ll r){
	ll num=a[l];
	for(int i=l+1;i<=r;i++){
		num^=a[i];
	}
	return num;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int op=1;
	for(int i=1;i<=n;i++){
		if(check(op,i)==k){
			op=i+1;
			ans++;
		}
	}
	cout<<ans;
}

