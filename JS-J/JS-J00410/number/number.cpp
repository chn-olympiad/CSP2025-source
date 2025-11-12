#include<bits/stdc++.h>
using namespace std;
long long ans[10000100];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	long long f=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ans[f] = s[i]-'0';
			f++;
		}
	}
	sort(ans-1,ans+f);
	for(int j=f-1;j>=0;j--)
	{
		cout << ans[j];
	}
	
	return 0;
}
