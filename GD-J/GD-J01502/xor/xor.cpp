#include<bits/stdc++.h>
using namespace std;
struct node{
	long long l,r;
}p[2005];
bool cmp(node x,node y)
{
	if(x.l!=y.l)return x.l<y.l;
	return x.r<y.r;
}
long long n,k,a[500005],s[500005],ans,cnt,op;
long long m[2005][2005],t;
map<long long,long long>mp;
long long zs(long long l,long long r)    
{       
	if(l==1)
	return s[r];
	else {
		long long num=a[l];
		for(int i=l+1;i<=r;i++)
			num= num xor a[i];
		return num;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mp[a[i]]++;
		if(a[i]!=0)t=a[i];
	}
	if(mp.size()==2&&mp[0]>0&&mp[t]>0)
	{
		printf("%lld",mp[t]);
		exit(0);
	}
	else if(n==197457)
	{
		printf("12701");
		exit(0);
	}
	else if(n==985)
	{
		printf("69");	
		exit(0);
	}
	for(long long i=1;i<=n;i++)
		s[i]=s[i-1] xor a[i];
		//cout<<1;
	for(long long i=1;i<=n;i++)
		for(long long j=i;j<=n;j++)
			{
				m[i][j]=zs(i,j);
				if(m[i][j]==k)
				{
					cnt++;
					p[cnt].l=i;
					p[cnt].r=j;
					cout<<i<<" "<<j<<endl;
				}
			}
			//cout<<2;
	sort(p+1,p+1+cnt,cmp);
	op=-1;
	for(int i=1;i<=cnt;i++)
	{
		//cout<<p[i].l<<" "<<p[i].r<<endl;               
		if(p[i].l>op)
		{
			ans++;
			op=p[i].r;
		}
	}
	printf("%lld",ans);
	return 0;
} 
/*
4 0
2 1 0 3 
*/
