#include <bits/stdc++.h>
using namespace std;
//long long
long long a[5005],maxn[5005],cnt = 0,q[5005],n;

long long temp[5005];

void dfs(long long maxnn,long long step,long long choose,long long sum,bool is0)
{
	if(step > n)return;
	
	if(step >= 3 && sum > 2*maxnn && is0 == 0)
	{
		cnt++;
		cnt %= 998244353;
	}
	temp[step+1] = 1;
	dfs(max(maxnn,a[step+1]),step+1,choose+1,sum+a[step+1],0);
	temp[step+1] = 0;
	dfs(maxnn,step+1,choose,sum,1);
}

signed main()
{
	//cff I love you,Õâ·Ö¸øµÄºÃ 
	//zphµÄÌØÉ«±ê¼Ç
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
	bool is1 = 1;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin >> n;
	for(long long i = 1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i] != 1)is1 = 0;
	}
	if(is1 == 1)
	{
		//3
		// 1 1 1 -> 1
		//4
		// 1 1 1 1 
		// 3 -> 2
		// 4 -> 1
		//5
		//1 1 1 1 1 
		//3 -> 3
		//4 -> 2
		//5 -> 1
		//n
		//
		//last:(n-2)
		//first:1
		for(long long i = 1;i<=n-2;i++)
		{
			cnt+=i;
			cnt%=998244353;
		}
		cout << cnt;
		return 0;
	}
	sort(a+1,a+n+1);
	temp[1] = 1;
	dfs(a[1],1,1,a[1],0);
	temp[1] = 0; 
	dfs(0,1,0,0,1); 
	cout << cnt % 998244353;
	return 0;
}
//dp
