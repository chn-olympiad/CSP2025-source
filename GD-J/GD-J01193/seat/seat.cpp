#include <bits/stdc++.h>
using namespace std;
//long long
long long a[1005];
long long b[105][105];

bool cmp(int x,int y)
{
	return x>y; 
}

signed main()
{
	//µÚÒ»´ÎÔÚT2¿´¼ûµ¥´¿µÄÄ£Äâ 
	//zphµÄÌØÉ«±ê¼Ç
	//ccf orz
	//noi orz
	//cspj orz
	//luogu orz
	//tuling orz
	//noip orz
	//csps orz
	//teachers orz
	//machine orz
	//all things orz
	//ÇòÇòccf±ð±¬Áã£¬µù£¡ 
	//ÇòÇòccf±ð±¬Áã£¬µù£¡ 
	//ÇòÇòccf±ð±¬Áã£¬µù£¡ 
	//ÇòÇòccf±ð±¬Áã£¬µù£¡ 
	//ÇòÇòccf±ð±¬Áã£¬µù£¡ 
	//ÇòÇòccf±ð±¬Áã£¬µù£¡ 
	//ÇòÇòccf±ð±¬Áã£¬µù£¡ 
	//ÇòÇòccf±ð±¬Áã£¬µù£¡ 
	//ÇòÇòccf±ð±¬Áã£¬µù£¡ 
	//ÇòÇòccf±ð±¬Áã£¬µù£¡ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0); 
	long long n,m;
	cin >> n >> m;
	for(long long i = 1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	long long ttt = a[1];
	sort(a+1,a+n*m+1,cmp);
	long long cur = 1;
	for(long long i = 1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(long long j = 1;j<=n;j++)
			{
				b[j][i] = a[cur];
				cur++;
			}	
		}
		else
		{
			for(long long j = n;j>=1;j--)
			{
				b[j][i] = a[cur];
				cur++;
			}
		}
	}
long long tx = -1,ty = -1;
	for(long long i = 1;i<=n;i++)
	{
		for(long long j = 1;j<=m;j++)
		{
			//cout << b[i][j] << ' ';
			if(b[i][j] == ttt)
			{
				tx = i;
				ty = j;	
			}	
		}
	}
	cout << ty << ' ' << tx << endl;
	return 0;
}
