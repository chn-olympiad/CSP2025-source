#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p1=101,p2=107,M1=1e9+7,M2=1e9+9;
const int N=2e5+10,M=5e6+10;
ll k1[M],k2[M];
vector<ll> e1[N],e2[N];
ll e3[M],e4[M];
struct Node1
{
	int l;
	int r;
	ll x;
	ll y;
	int id;
	int len;
}a[N];

bool cmd(Node1 a,Node1 b)
{
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}

int bhalf(int l,int r,ll x)
{
	int mid=(l+r)>>1,ans=-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[mid].x<x) l=mid+1;
		else if(a[mid].x>x) r=mid-1;
		else ans=mid,r=mid-1;
	}
	return ans;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read(),d=0;
	string s1,s2;
	k1[0]=k2[0]=1;
	for(int i=1;i<=M-10;i++)
	{
		k1[i]=(k1[i-1]*p1)%M1;
		k2[i]=(k2[i-1]*p2)%M2;
	}
	
	for(int i=1;i<=n;i++)
	{
		cin >> s1 >> s2;
		int len=s1.size();
		int l=0,r=0;
		e1[i].push_back(0);
		e2[i].push_back(0);
		for(int j=0;j<len;j++)
		{
			e1[i].push_back((e1[i][j]*p1+s1[j]-'a'+1)%M1);
			e2[i].push_back((e2[i][j]*p1+s2[j]-'a'+1)%M1);
			if(s1[j]==s2[j])
				if(l==j) l=j+1;
			if(s1[j]!=s2[j])
				r=j+1;
		}
		ll x=((e1[i][r]-(e1[i][l]*k1[r-l]))%M1+M1)%M1;
		ll y=((e2[i][r]-(e2[i][l]*k1[r-l]))%M1+M1)%M1;
		a[i].l=l,a[i].r=r,a[i].x=x,a[i].y=y;
		a[i].id=i;a[i].len=len;
	}
	sort(a+1,a+n+1,cmd);
	for(int i=1;i<=q;i++)
	{
		d=0;
		cin >> s1 >> s2;
		if(s1.size()!=s2.size())
		{
			puts("0");
			continue;
		}
		int len=s1.size();
		int l=0,r=0;
		for(int j=0;j<len;j++)
		{
			e3[j+1]=((e3[j]*p1+s1[j]-'a'+1)%M1);
			e4[j+1]=((e4[j]*p1+s2[j]-'a'+1)%M1);
			if(s1[j]==s2[j])
				if(l==j) l=j+1;
			if(s1[j]!=s2[j])
				r=j+1;
		}
		ll x=((e3[r]-(e3[l]*k1[r-l]))%M1+M1)%M1;
		ll y=((e4[r]-(e4[l]*k1[r-l]))%M1+M1)%M1;
		int z=bhalf(1,n,x);
		while(z!=-1 and a[z].x==x and z<=n)
		{
			if(a[z].y==y)
			{
				int id=a[z].id;
				int l2=a[z].l,r2=a[z].len-a[z].r;
				if(l<l2 or len-r<r2) {z++;continue;}
				ll xx=((e3[r+r2]-(e3[l-l2]*k1[r+r2-l+l2]))%M1+M1)%M1;
				ll yy=((e4[r+r2]-(e4[l-l2]*k1[r+r2-l+l2]))%M1+M1)%M1;
				if(xx==e1[id][a[z].len] and yy==e2[id][a[z].len]) d++;
			}
			z++;
		}
		printf("%d\n",d);
	}
	return 0;
}
