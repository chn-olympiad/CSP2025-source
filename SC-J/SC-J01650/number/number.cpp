#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const LL N=1e1+9;
string s;
LL num[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(LL i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') num[s[i]-'0']++;
	}
	for(LL i=9;i>=0;i--)
	{
		while(num[i]--)
		{
			cout<<i;
		}
	}
	return 0;
}