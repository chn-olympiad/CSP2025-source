#include<bits/stdc++.h>
using namespace std;
string s;int ans[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') ans[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=ans[i];j++) cout<<i;
	return 0;
}
/*
froepen("number.in","r",stdin);
froepen("number.out","w",stdout);
freopem("number.in","r",stdin);
freopem("number.out","w",stdout);
上面这些东西都是用来诈骗你的 awa
不会这道题有人用了sort吧 
*/
