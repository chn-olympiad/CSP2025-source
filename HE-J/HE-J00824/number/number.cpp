#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
string s;
int a[1000010];
ll k=0;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),cout.tie(0);
	std::cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k,cmp);
	for(ll i=1;i<=k;i++)
	{
		std::cout<<a[i];
	}
	return 0;
}
/*
Our base is being attack.
最绝望的死法
//freopen 
*/
