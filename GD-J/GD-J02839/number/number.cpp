#include<bits/stdc++.h>
using namespace std;
int n,t[15];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(t[i]--)cout<<i;
	}
	return 0;
}
