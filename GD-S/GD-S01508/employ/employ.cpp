#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
char a[100000+10];
ll b[1000000+10],ans=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=='1'){
			ans++;
		}
	}
	
	for(ll i=1;i<=n;i++){
		cin>>b[i];
	}
	if(ans==n){
		cout<<n% 998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
