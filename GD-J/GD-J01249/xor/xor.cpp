#include<bits/stdc++.h>
using namespace std;
struct d{int l,r;}jl[500005];
long long Q,k,n,m,a[500005],s,t,ans=1,zd=-1e18,c;
string st;
bool cmp(d x,d y)
{
	if(x.l==y.l) return x.r<y.r;
	else return x.l<y.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]==1) s++;
		else t++;
	}
	if(k==0 && s==n) cout<<s/2;
	else if(k==0 && s==0) cout<<t;
	else if(k==1 && s==n) cout<<s;
	else if(k==1 && s==0) cout<<t/2;
	else
	{
		if(k==0)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1 && a[i+1]==1) ans++;
				i++;
			}
			cout<<t+ans;
		}
		else 
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0 && a[i+1]==0) ans++;
				i++;
			}
			cout<<s+ans;
		}
	}
	/*s[1]=a[1];
	for(int i=2;i<=n;i++) s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(s[j]^s[i-1]==k) jl[++c].r=j,jl[c].l=i;
		}
	}
	sort(jl+1,jl+1+c,cmp);
	for(int i=1;i<=n;i++)
	{
		cout<<jl[i].l<<' '<<jl[i].r<<"\n";
	}
	for(int i=1;i<=c;i++)
	{
		ans=1;
		int x=jl[i].r;
		for(int j=i+1;j<=c;j++)
		{
			if(jl[j].l>x) 
			{
				ans++;
				x=jl[j].r;
			}
		}
		zd=max(zd,ans);
	}
	cout<<zd;*/
	return 0;
}
