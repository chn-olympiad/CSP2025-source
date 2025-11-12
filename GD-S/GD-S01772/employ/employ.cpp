#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[505],ans=0;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	} 
	for(int i=1;i<=m;i++){
		ans*=(n-i+1);
		ans%=998224358;
	}
	cout<<ans;
	return 0;
	}
