#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=n-i+1;j>=1;j--)
		ans=(ans+1)%998244353;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
