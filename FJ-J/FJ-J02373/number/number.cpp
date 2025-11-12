#include<bits/stdc++.h>
using namespace std;
#define int long long
int num[60];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin>>s; 
	for(int i=0;s[i];i++)
	{
		if('0'<=s[i]<='9')
		{
			num[s[i]]++;
		}
	}
	string ans;
	for(int i=57;i>=48;i--) //ASCII 0=48 ASCII 9=57
	{
		if(num[i]!=0)
		{
			while(num[i]--)
			{
				ans+=(char)(i);
			}
		}
		else
		{
			continue;
		}
	}
	cout<<ans<<endl;

	return 0;
}

