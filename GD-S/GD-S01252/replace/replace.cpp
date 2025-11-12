#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=5e6+5;
unsigned long long p=1584517313;
unsigned long long c[maxm];
void init()
{
	c[0]=1;
	for(int i=1;i<maxm;i++)c[i]=c[i-1]*p;
}
struct ss
{
	int len;
	unsigned long long num1,num2;
}a[maxn];
unsigned long long hx(string qb)
{
	int n=qb.size();
	unsigned long long num=0;
	for(int i=0;i<n;i++)num=num*p+(qb[i]-'a'+1);
	return num;
}
unsigned long long b[maxm];
void init_hx1(string qb)
{
	b[0]=0;
	int n=qb.size();
	for(int i=1;i<=n;i++)b[i]=b[i-1]*p+(qb[i-1]-'a'+1);
}
unsigned long long d[maxm];
void init_hx2(string qb)
{
	d[0]=0;
	int n=qb.size();
	for(int i=1;i<=n;i++)d[i]=d[i-1]*p+(qb[i-1]-'a'+1);
}
unsigned long long ask1(int l,int r)
{
	r++,l++;
	return b[r]-b[l-1]*c[r-l+1];
}
unsigned long long ask2(int l,int r)
{
	r++,l++;
	return d[r]-d[l-1]*c[r-l+1];
}
bool cmp(ss A,ss B)
{
	return A.len<B.len;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++)
	{
		string qb;
		cin>>qb;
		a[i].len=qb.size();
		init_hx1(qb);
		a[i].num1=ask1(0,a[i].len-1);
		cin>>qb;
		init_hx1(qb);
		a[i].num2=ask1(0,a[i].len-1);
//		cout<<a[i].num1<<' '<<a[i].num2<<'\n';
	}
	sort(a+1,a+1+n,cmp);
	if(n>1e3)
	{
		return 0;
	}
	while(m--)
	{
		string qb;
		cin>>qb;
		int len=qb.size();
		init_hx1(qb);
		cin>>qb;
		init_hx2(qb);
		int s=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].len>len)break;
			for(int j=0;j+a[i].len-1<len;j++)
			{
//				cout<<ask1(j,j+a[i].len-1)<<' '<<ask2(j,j+a[i].len-1)<<'\n';
				if(a[i].num1==ask1(j,j+a[i].len-1) && a[i].num2==ask2(j,j+a[i].len-1))
				{
					if(ask1(0,j-1)==ask2(0,j-1) && ask1(j+a[i].len,len-1)==ask2(j+a[i].len,len-1))s++;
				}
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

1 1
bc de
xabcx xadex
*/
