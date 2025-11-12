#include<bits/stdc++.h>
using ll=long long;
using namespace std;
/*
显然是不会正解的，于是看向特殊性质，
A:s=1全都会写，那就是n人的全排列嘛
m=n就是让所有人都录取，额如果不是所有的s=1的话，那显然不可能
m=1应该也有讲究，但是没时间了 
*/

const ll mo = 998244353;

ll ans = 0;
bool f[505], mark[505];
int n, m;
int r[505];

void dfs(int x,int c)
//录取了x人，离开了c人 
{
	if(c > n-m)return ;//离开的人已经比预计离开的最大人数多了 
	if(x+c == n)
	{
		ans++;//都到这里了肯定是成了 
		ans %= mo;
		//printf("yes\n");
		return ;
	}
	if(x >= m)//如果此时录取的人数已经到了预计录取的人数了 
	{
		//那后面就直接全排列了
		ll op = 1;
		for(int i = 2;i <= n-x;i++)op = op*i%mo;
		ans = (ans+op)%mo;
		return ;
	} 
	for(int i = 1;i <= n;i++)
	{
		if(mark[i]==0)
		{
			mark[i]=1;
			//printf("c=%d %d %d\n",c,x);
			if(f[x]==0||c>=r[i])dfs(x,c+1);
			else dfs(x+1,c);
			mark[i]=0;
		}
	}
	return ; 
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	char ch;
	bool op = 1;//是否全都为1 
	for(int i = 1;i <= n;i++)
	{
		scanf(" %c",&ch);
		f[i]=ch-'0';
		op &=f[i]; 
	}
	int num = n; //真的会来面试的人。 
	for(int i = 1;i <= n;i++){scanf("%d",&r[i]);num-=(r[i]==0);}
	//很显然，如果r==0的话，那不管怎么样都不可能去面试的了 
	//printf("op=%d\n",op);
	if(op)//难度全为1，是n个人的全排列 
	{
		ans = 1;
		for(ll i =2;i <= num;i++)ans = ans*i%mo;
		printf("%lld\n",ans);
		return 0;
	}
	if(n == m)printf("0\n");
	//如果是m==n的情况就是要全部录取，那就是要所有人都能做出来题 
	//但是所有人都做出来题的全排列在上面了，所以剩下来一定有人做不出来题，总之方案数0 
	else if(num < m)printf("0\n");//来面试的人小于要录取的人。
	else 
	{
		dfs(0,0); 
		printf("%lld\n",ans);
	}
	return 0;
} 
