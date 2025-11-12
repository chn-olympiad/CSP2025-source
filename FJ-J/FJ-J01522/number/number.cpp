#include <bits/stdc++.h>
using namespace std;
string s;
int ans[1000010],j;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			ans[j]=s[i]-'0';
			j++;
		}
	}
	sort(ans,ans+j);
	for(int i=j-1;i>=0;i--) cout<<ans[i];
	return 0;
}
