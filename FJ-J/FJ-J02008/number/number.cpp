#include <bits/stdc++.h>
using namespace std;
bool l=false;
int cnt=1,a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a[cnt]=s[i]-'0';
			cnt++;
		}
	sort(a+1,a+cnt);
	for(int i=cnt;i>=1;i--)
	{
		if(a[i]==0)
		{
			if(l) cout<<a[i];
		}
		else
		{
			cout<<a[i];
			l=true;
		}
	}
	return 0;
} 
