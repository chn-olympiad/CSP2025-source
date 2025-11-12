#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+10;
string s;
ll ans=0,num[N]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			ans++;
			num[ans]=0;
		}
		else if(s[i]=='1')
		{
			ans++;
			num[ans]=1;
		}
		else if(s[i]=='2')
		{
			ans++;
			num[ans]=2;
		}
		else if(s[i]=='3')
		{
			ans++;
			num[ans]=3;
		}
		else if(s[i]=='4')
		{
			ans++;
			num[ans]=4;
		}
		else if(s[i]=='5')
		{
			ans++;
			num[ans]=5;
		}
		else if(s[i]=='6')
		{
			ans++;
			num[ans]=6;
		}
		else if(s[i]=='7')
		{
			ans++;
			num[ans]=7;
		}
		else if(s[i]=='8')
		{
			ans++;
			num[ans]=8;
		}
		else if(s[i]=='9')
		{
			ans++;
			num[ans]=9;
		}
	}
	sort(num+1,num+ans+1);
	for(ll i=ans;i>=1;i--)
	{
		cout<<num[i];
	}
	return 0;
}
