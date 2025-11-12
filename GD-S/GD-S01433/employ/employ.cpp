#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==0) return cout<<0,0;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0')  return cout<<0,0;
	}
	cout<<1;
}
