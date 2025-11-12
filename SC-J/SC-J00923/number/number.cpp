#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n;
int t[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++)
		if(s[i-1]>='0'&&s[i-1]<='9')
			t[s[i-1]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=t[i];j++)cout<<i;
	return 0;
}