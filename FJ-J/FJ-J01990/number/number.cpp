#include<bits/stdc++.h>
using namespace std;
string s;
int sz[20000000];
int cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sz[++cnt]=s[i]-'0';
		}
	}
	sort(sz+1,sz+1+cnt);
	for(int i=1;i<=cnt;i++)cout<<sz[cnt-i+1];
	cout<<endl;
	return 0;
}

