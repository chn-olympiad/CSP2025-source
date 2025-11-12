#include<bits/stdc++.h>
using namespace std;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	static int num[10];
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(isdigit(s[i]))
			num[s[i]^48]++;
	for(int i=9;i>=0;i--)
		for(int j=0;j<num[i];j++)
			cout<<i;
	cout<<'\n';
	return 0;
}