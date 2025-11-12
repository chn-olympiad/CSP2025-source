#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace fastIO{
	int read()
	{
		char c;
		int sum=0,res=1;
		c=getchar();
		while(c>'9'||c<'0')
		{
			if(c=='-')res=-1;
			c=getchar();
		}
		while(c<='9'&&c>='0')
		{
			sum=(c-'0')+sum*10;
			c=getchar();
		}
		return sum*res;
	}
	void out(int sum)
	{
		if(sum<0)
		{
			putchar('-');
			sum=-sum;
		}
		if(sum<10)
		{
			putchar(sum+'0');
		}
		else
		{
			out(sum/10);
			putchar(sum%10+'0');
		}
	}
	void wenjian()
	{
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
	}
};
int tong[1008617];
signed main()
{
	fastIO::wenjian();
	string s;
	cin>>s;
    for(int i=0;i<s.length();i++)if(s[i]<='9'&&s[i]>='0')tong[s[i]-'0']++;
	for(int i=9;i>=0;i--)while(tong[i]--)fastIO::out(i);
	return 0;
}
//100 pts at 8:45
