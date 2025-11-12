#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt[10];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool b=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		cnt[s[i]-'0']++;
	}
	for(int i=9;i>0;i--)
	{
		while(cnt[i]--)
		{	
			b=1;
			cout<<i;
		}
	}
	if(b==1)
		while(cnt[0]--)cout<<'0';
	else if(b==0)
	{
		cout<<'0';
	}
	return 0;
}
