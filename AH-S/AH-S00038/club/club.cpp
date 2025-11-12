#include<cstdio>
#include<string.h>
#include<algorithm>
//#define long long long long
using namespace std;
long long a[1001000][5];
long long s[5];
long long ans[5];
long long lu = 20010;
struct node
{
	long long id;
	long long mn;
	long long mxm;
	long long sum;
};
node tr[4001000][5];
void push(long long u,long long l,long long r,long long i,long long n,long long m,long long id)
{
	if(l == r)
	{
		tr[u][i].mn = a[id][n] - a[id][m];
		tr[u][i].mxm = m;
		tr[u][i].id = id;
		if(tr[u][i].sum > 1000000)	tr[u][i].sum = 1;
		else tr[u][i].sum++;
		return ;
	}
	long long mid = l + r >> 1;
	long long x = a[id][n] - a[id][m];
	if(x <= mid)	push(u << 1,l,mid,i,n,m,id);
	if(x > mid)	push(u << 1 | 1,mid + 1,r,i,n,m,id);
	if(tr[u << 1][i].mn < tr[u << 1 | 1][i].mn)
	{
		tr[u][i].mn = tr[u << 1][i].mn;
		tr[u][i].id = tr[u << 1][i].id;
		tr[u][i].mxm = tr[u << 1][i].mxm;
		tr[u][i].sum = 0;
	}
	else
	{
		tr[u][i].mn = tr[u << 1 | 1][i].mn;
		tr[u][i].id = tr[u << 1 | 1][i].id;
		tr[u][i].mxm = tr[u << 1 | 1][i].mxm;
		tr[u][i].sum = 0;
	}
}
void pop(long long u,long long l,long long r,long long i,long long n,long long m,long long id)
{
	//printf("aaa%lld %lld %lldaaa\n",tr[u][i].sum,l,r);
	if(l == r)
	{
		tr[u][i].sum--;
		//printf("aaa%lldaaa\n",tr[u][i].sum);
		if(!tr[u][i].sum)
		{
			tr[u][i].mn = 1 << 30;
			//tr[u][i].mxm = m;
			//tr[u][i].id = id;
			//tr[u][i].sum++;
		}
		return ;
	}
	//printf("x")
	long long mid = l + r >> 1;
	long long x = a[id][n] - a[id][m];
	if(x <= mid)	pop(u << 1,l,mid,i,n,m,id);
	if(x > mid)	pop(u << 1 | 1,mid + 1,r,i,n,m,id);
	if(tr[u << 1][i].mn < tr[u << 1 | 1][i].mn)
	{
		tr[u][i].mn = tr[u << 1][i].mn;
		tr[u][i].id = tr[u << 1][i].id;
		tr[u][i].mxm = tr[u << 1][i].mxm;
	}
	else
	{
		tr[u][i].mn = tr[u << 1 | 1][i].mn;
		tr[u][i].id = tr[u << 1 | 1][i].id;
		tr[u][i].mxm = tr[u << 1 | 1][i].mxm;
	}
}
//long long find(long long u,long long l,long long r,long long x)
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		memset(tr,0x3f,sizeof(tr));
		memset(s,0,sizeof(s));
		memset(ans,0,sizeof(ans));
		//printf("aaa%daaa\n",tr[1][1].sum);
		long long n;
		scanf("%lld",&n);
		long long i;
		for(i = 1;i <= n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(i = 1;i <= n;i++)
		{
			//long long mx;
			long long mx = max(max(a[i][1],a[i][2]),a[i][3]);
			if(mx == a[i][1])
			{
				long long m;
				if(a[i][2] > a[i][3])	m = 2;
				else	m = 3;
				push(1,-1,lu,1,1,m,i);
				s[1]++;
				ans[1] += mx;
			}
			else if(mx == a[i][2])
			{
				long long m;
				if(a[i][1] > a[i][3])	m = 1;
				else	m = 3;
				push(1,-1,lu,2,2,m,i);
				s[2]++;
				ans[2] += mx;
			}
			else if(mx == a[i][3])
			{
				long long m;
				if(a[i][2] > a[i][1])	m = 2;
				else	m = 1;
				push(1,-1,lu,3,3,m,i);
				s[3]++;
				ans[3] += mx;
			}
		}
		//printf("%lld %lld %lld\n",s[1],s[2],s[3]);
		long long flag = 0;
		for(i = 1;flag <= 5;i++)
		{
			long long x = (i - 1) % 3 + 1;
			if(s[x] <= n / 2)
			{
				flag++;
				continue;
			}
			flag = 0;
			//printf("d%d %d\n",x,s[x]);
			while(s[x] > n / 2)
			{
				long long id = tr[1][x].id;
				long long mn = tr[1][x].mn;
				long long mxm = tr[1][x].mxm;
				//printf("b%lld %lld %lld %lld\n",x,a[id][mxm],id,a[id][mxm] + mn);
				s[x]--;
				ans[x] -= a[id][mxm] + mn;
				s[mxm]++;
				ans[mxm] += a[id][mxm];
				//printf("c%lld %lld %lld %lld\n",x,ans[x],mxm,ans[mxm]);
				push(1,-1,lu,mxm,mxm,6 - mxm - x,id);
				pop(1,-1,lu,x,x,mxm,id);
			}
			//printf("------------------------------------------%lld %lld %lld\n",s[1],s[2],s[3]);
		}
		printf("%lld\n",ans[1] + ans[2] + ans[3]);
		//printf("a%d %d %d\n",tr[1][1].mn,tr[1][2].mn,tr[1][3].mn);
	}
	return 0;
}
