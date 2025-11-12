#include<bits/stdc++.h>
#define ls u<<1
#define rs u<<1|1
using namespace std;
const int MAXN=500005;
bool terb=true;
int n,k,ans,sum,ansmax;
int num[MAXN],f[MAXN],mx[MAXN*4];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void pushup(int u)
{
	mx[u]=max(mx[ls],mx[rs]);
	return ;
}
void change(int u,int l,int r,int pos)
{
	if(l==r)
	{
		mx[u]=f[pos];
		return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) change(ls,l,mid,pos);
	else change(rs,mid+1,r,pos);
	pushup(u);
	return ;
}
int query(int u,int l,int r,int ql,int qr)
{
	if(ql>qr)
	{
		return 0;
	}
	if(ql<=l&&r<=qr)
	{
		return mx[u];
	}
	int mid=l+r>>1,res=-1;
	if(ql<=mid) res=max(res,query(ls,l,mid,ql,qr));
	if(qr>mid) res=max(res,query(rs,mid+1,r,ql,qr));
	return res;
}
void work()
{
	int sum0=0,sum1=0;
	for(int i=1;i<=n;i++)
	{
		if(num[i]==0) sum0++;
		else sum1++;
	}
	if(k==0) printf("%d",sum0);
	else printf("%d",sum1);
	return ;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		num[i]=read();
		if(num[i]>1)
		{
			terb=false;
		}
	}
	if(terb)
	{
		work();
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		sum=0;
		f[i]=max(query(1,1,n,1,i-1),f[i]);
		for(int j=i;j<=n;j++)
		{
			sum^=num[j];
			if(sum==k)
			{
				if(f[i-1]+1>f[j])
				{
					f[j]=f[i-1]+1;
					change(1,1,n,j);
				}
//				f[j]=max(f[j],f[i-1]+1);
//				change(1,1,n,j);
			}
		}
	}
	printf("%d",/*query(1,1,n,1,n)*/f[n]);
	return 0;
}
//4 2 2 1 0 3
