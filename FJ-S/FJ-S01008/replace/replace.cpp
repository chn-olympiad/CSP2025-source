#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
bool pd;
struct ds{
	string a,b;
	int l;
}e[300000];
bool cmp(ds x,ds y)
{
	return x.l>y.l;
}
signed main()
{
	string x,y;
	int l,r,ll;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
	  cin>>e[i].a>>e[i].b;
	  e[i].l=e[i].a.length();
	}
	sort(e+1,e+1+n,cmp);
	while(q)
	{
		q--;
		cin>>x>>y;
		ll=x.length();ans=0;
		
		for(int i=0;i<ll;i++)
		  if(x[i]!=y[i])
		  {
		  	l=i;
		  	break;
		  }  
		for(int i=ll-1;i>=0;i--)
		  if(x[i]!=y[i])
		  {
		  	r=i;
		  	break;
		  }
		for(int i=1;e[i].l>r-l&&i<=n;i++)
		  for(int j=max(r-e[i].l+1,0);j<=l;j++)
		  {
		  	pd=1;
		  	for(int k=0;k<e[i].l;k++)
		  	  if(e[i].a[k]!=x[j+k]||e[i].b[k]!=y[j+k])
		  	  {
		  	  	pd=0;
		  	  	break;
			  }
			ans+=pd;
		  }
		cout<<ans<<'\n';
	}
	return 0;
}

