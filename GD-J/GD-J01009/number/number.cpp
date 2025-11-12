#include<bits/stdc++.h>
using namespace std;
const int M=20;
string s;int n,t[M];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	for(register int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			++t[s[i]-'0'];
	}
	for(register int i=9;i>=0;i--)
		for(register int j=1;j<=t[i];j++)
			cout<<i; 
	return 0;
}
