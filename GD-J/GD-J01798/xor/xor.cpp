#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500010];
ll n,k,tot,tot2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	bool flag=false,temp=false;
	for(ll i;i<=n;i++){
		cin >> a[i];
		if(a[i]==0)flag=true,tot++;
		if(a[i]==1)temp=true;
		if(a[i]==1 && temp)temp==false,tot++;
		if(a[i]==1 || (a[i]==1 && a[i-1]==0))tot2++;
	}
	if(!flag){
		if(k==1)cout << n;
		if(k==0)cout << n/2;
	}
	if(flag){
		if(k==0)cout << tot;
		if(k==1)cout << tot2;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
