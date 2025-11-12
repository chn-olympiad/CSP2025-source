#include<bits/stdc++.h>
using namespace std;
string s;
int v[1000010];
int t=0;
int main()
{
  freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]>="0"&&s[i]<="9")
		{
			v[t]=s[i];
			t++;
		}
	}
	for(int i=0;i<t;++i)
	{
		cout<<v[i];
	}
	return 0;
}
