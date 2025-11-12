#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int N=1e6+10;
string s;
ll t[100];
ll maxn=-1e18;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=" "+s;
	for(int i=1;s[i]!='\0';i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			ll num=int(s[i]-'0');
			t[num]++;
			maxn=max(maxn,num);
		}
	}
	if(maxn==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=maxn;i>=0;i--)
	{
		f(j,1,t[i])
		{
			cout<<i;
		}
	}
	return 0;
} 
