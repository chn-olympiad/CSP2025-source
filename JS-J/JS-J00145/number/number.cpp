#include<bits/stdc++.h>
using namespace std;
int a,cnt;
string s;
int dp[1000006];
int maxn=-1;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){

		if((s[i]<='9'&&s[i]>='0'))
		{

			dp[++cnt]=s[i]-'0';
		}
	}
	sort(dp+1,dp+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
	    cout<<dp[i];

	}
	cout<<endl;
	return 0;
}
