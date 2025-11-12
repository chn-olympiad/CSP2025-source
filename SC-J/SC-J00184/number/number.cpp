#include<bits/stdc++.h>
using namespace std;
string s;
char t[1000005];
int tot=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')t[++tot]=s[i];
	sort(t+1,t+1+tot);
	for(int i=tot;i;i--)cout<<t[i];
	return 0;
}