#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,h[505],c[505],f[505];
string s;
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++) h[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	
	return 0;
}
