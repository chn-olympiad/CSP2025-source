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
		freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
	}
};
int qxor[1008617],n,k,a[1008617];
bitset<8388608> tong;
int solve()
{
	int ans=0;
	tong[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(tong[qxor[i]^k]==1)
		{
			ans++;
			tong=0;
		}
		tong[qxor[i]]=1;
	}
	return ans;
}
signed main()
{
	fastIO::wenjian();
    cin>>n>>k;
    for(int i=1;i<=n;i++)a[i]=fastIO::read(),qxor[i]=qxor[i-1]^a[i];
    cout<<solve();
    //2 3 3 0 
	return 0;
}
/*
100pts at 10:00
*/
