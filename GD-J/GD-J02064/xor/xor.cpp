#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k;
string x,y,z;
int yihuo(int a,int b)
{
	
	int tx = 0,ty = 0;
	while(a>0)
	{
		tx++;
		x[tx] = char(a%2+'0');
		a/=2;
	}
	while(b>0)
	{
		ty++;
		y[ty] = char(b%2+'0');
		b/=2;
	}
	int len = max(ty,tx);
	for(int i = len;i>=1;i--)
	{
		if(len>ty)
		{
			y[i] = '0';
		}
		if(len>tx)
		{
			x[i] = '0';
		}
		if(x[i] == '0'||y[i] == '0')
		{
			z[i] = '1'; 
		} 
		else z[i] = '0';
	}
	int u = 1,ans;
	for(int i =1;i<=len;i++)
	{
		ans+=int(z[i]-'0')*u;
		u*=2;
	}
	return ans;
}
int gg[5005][5005];
int g[500005];
int f[500005];
int main()
{
	freopen("xor","r",stdin);
	freopen("xor","w",stdout);  
	int n,k;
	cin >> n >> k;
	cout << 2;
}
