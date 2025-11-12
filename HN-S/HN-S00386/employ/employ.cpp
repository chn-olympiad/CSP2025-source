#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n+1];
	int ans=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]) ans*=c[i];
	}
	cout<<ans;
	return 0;
}

