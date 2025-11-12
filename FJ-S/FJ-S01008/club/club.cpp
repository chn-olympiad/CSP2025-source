#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans,al,bl,cl,va[300000],vb[300000],vc[300000];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	int z,a,b,c;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t)
	{
		cin>>n;
		ans=0;al=bl=cl=n;
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
			z=min(a,min(b,c));
			ans+=z;
			a-=z;b-=z;c-=z;
			if(a==0)
			  al--;
			if(b==0)
			  bl--;
			if(c==0)
			  cl--;
			va[i]=a;vb[i]=b;vc[i]=c;
		}
		for(int i=1;i<=n;i++)
		{
		  if(va[i]==0)
		  {
		  	z=min(vb[i],vc[i]);
		  	ans+=z;
		  	vb[i]-=z;
		  	vc[i]-=z;
		  }
		  if(vb[i]==0)
		  {
		  	z=min(va[i],vc[i]);
		  	ans+=z;
		  	va[i]-=z;
		  	vc[i]-=z;
		  }
		  if(vc[i]==0)
		  {
		  	z=min(va[i],vb[i]);
		  	ans+=z;
		  	va[i]-=z;
		  	vb[i]-=z;
		  }
		}
		sort(va+1,va+1+n,cmp);
		sort(vb+1,vb+1+n,cmp);
		sort(vc+1,vc+1+n,cmp);
		al=bl=cl=0;
		for(int i=1;i<=n;i++)
		{
		  	if(al<n/2)
		  	{
		  	  al++;
		  	  ans+=va[i];
			}
			if(bl<n/2)
			{
			  bl++;
			  ans+=vb[i];
			}
			if(cl<n/2)
			{
			  cl++;
			  ans+=vc[i];
			}
		}
	    cout<<ans<<'\n';
	    t--;
	}
	return 0;
}

