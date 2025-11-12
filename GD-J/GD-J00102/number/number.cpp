#include<bits/stdc++.h>
using namespace std;
string s,ans;
int f[1001];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	int n=s.size();
	for(int i=0,x=s[i]-'0'; i<n; i++,x=s[i]-'0') 
		if(x>=0&&x<=9)
			f[x]++;
	for(int i=9; i>=0; i--)
		for(int j=1; j<=f[i]; j++)
			ans+=i+'0';
	cout<<ans<<"\n";
	return 0;
}
