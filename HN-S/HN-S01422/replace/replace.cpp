#include<bits/stdc++.h>
using namespace std;
unsigned long long bas[5000005],qzh[5000005];
unsigned long long hshl[200005],hshr[200005],hshx[200005],hshy[200005];
int ll[200005],rr[200005];
const int p=1331;
unsigned long long hsh(int l,int r)
{
	if(l>r) return 0;
	return qzh[r]-qzh[l-1]*bas[r-l+1];
}
struct stu{
	int l,r,id,op;
}a[200005],qry[200005];
bool comp(stu a,stu b)
{
	return a.l<b.l;
}
int c[5000005][2],ans[200005];
void add(int x,int op)
{
	while(x<=5000001)
	{
		c[x][op]++;
		x+=(x&(-x));
	}
}
int sum(int x,int op)
{
	int tot=0;
	while(x)
	{
		tot+=c[x][op];
		x-=(x&(-x));
	}
	return tot;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	if(n*q<=1e8)
	{
		bas[0]=1;
		for(int i=1;i<=5e6;i++) bas[i]=bas[i-1]*p;
		for(int i=1;i<=n;i++)
		{
			string s1,s2;
			cin>>s1>>s2;
			int l=-1,r=0;
			for(int j=0;j<s1.size();j++)
			{
				if(s1[j]!=s2[j])
				{
					if(l==-1) l=j;
					r=j;
				}
			}
			if(l==-1)
			{
				l=0;
				r=s1.size()-1;
			}
			for(int j=0;j<s1.size();j++)
			{
				if(j<l)
				{
					hshl[i]=hshl[i]*p+s1[j];
					ll[i]++;
				}
				if(j>r)
				{
					hshr[i]=hshr[i]*p+s1[j];
					rr[i]++;
				}
				if(j<=r&&l<=j)
				{
					hshx[i]=hshx[i]*p+s1[j];
					hshy[i]=hshy[i]*p+s2[j];
				}
			}
		}
		while(q--)
		{
			string t1,t2;
			cin>>t1>>t2;
			if(t1.size()!=t2.size())
			{
				cout<<0<<'\n';
				continue;
			}
			int l=-1,r=0;
			for(int i=0;i<t1.size();i++)
			{
				if(t1[i]!=t2[i])
				{
					if(l==-1) l=i;
					r=i;
				}
				qzh[i+1]=qzh[i]*p+t1[i];
			}
			unsigned long long x=0,y=0;
			for(int i=l;i<=r;i++)
			{
				x=x*p+t1[i];
				y=y*p+t2[i];
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(hshx[i]==x&&hshy[i]==y)
				{
					if(l-ll[i]+1>=1&&r+rr[i]+1<=t1.size())
					{
						if(hsh(l-ll[i]+1,l)==hshl[i]&&hsh(r+2,r+rr[i]+1)==hshr[i]) ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	else
	{
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			string s1,s2;
			cin>>s1>>s2;
			int l=-1,r=0;
			for(int j=0;j<s1.size();j++)
			{
				if(s1[j]!=s2[j])
				{
					if(l==-1) l=j;
					r=j;
				}
			}
			if(l==-1) continue;
			if(s1[l]=='b')
			{
				a[++tot]={l,(int)s1.size()-r-1,0,0};
			}
			else
			{
				a[++tot]={l,(int)s1.size()-r-1,0,1};
			}
		}
		sort(a+1,a+tot+1,comp);
		int totq=0;
		for(int i=1;i<=q;i++)
		{
			string t1,t2;
			cin>>t1>>t2;
			if(t1.size()==t2.size())
			{
				int l=-1,r=0;
				for(int j=0;j<t1.size();j++)
				{
					if(t1[j]!=t2[j])
					{
						if(l==-1) l=j;
						r=j;
					}
				}
				if(t1[l]=='b')
				{
					qry[++totq]={l,(int)t1.size()-r-1,i,0};
				}
				else
				{
					qry[++totq]={l,(int)t1.size()-r-1,i,1};
				}
			}
		}
		sort(qry+1,qry+totq+1,comp);
		int tp=1;
		for(int i=1;i<=tot;i++)
		{
			add(a[i].r+1,a[i].op);
			if(a[i].l==a[i+1].l&&i!=tot) continue;
			while(tp<=totq&&qry[tp].l<=a[i].l)
			{
				ans[qry[tp].id]=sum(qry[tp].r+1,qry[tp].op);
				tp++;
			}
		}
		for(int i=1;i<=q;i++)
		{
			cout<<ans[i]<<'\n';
		}
	}
	return 0; 
}
