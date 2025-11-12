#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct zb
{
	   int a,b,c,ai,bi,ci;
}x[N];
int t,n;
long long sum;
int f[5];
bool cmp(zb l,zb r)
{
	 return l.a-l.b>r.a-r.b;
	 
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
		  memset(f,0,sizeof f);
		  cin>>n;
		  sum=0;
		  for(int i=1;i<=n;i++)
		  {
			  cin>>x[i].a>>x[i].b>>x[i].c;
			  x[i].ai=1;
			  x[i].bi=2;
			  x[i].ci=3;
			  if(x[i].a<x[i].b)
			  {
				 int tmp=x[i].a;
				 x[i].a=x[i].b;
				 x[i].b=tmp;
				 tmp=x[i].ai;
				 x[i].ai=x[i].bi;
				 x[i].bi=tmp;
			  }
			  if(x[i].a<x[i].c)
			  {
				 int tmp=x[i].a;
				 x[i].a=x[i].c;
				 x[i].c=tmp;
				 tmp=x[i].ai;
				 x[i].ai=x[i].ci;
				 x[i].ci=tmp;
			  }
			  if(x[i].b<x[i].c)
			  {
				 int tmp=x[i].b;
				 x[i].b=x[i].c;
				 x[i].c=tmp;
				 tmp=x[i].bi;
				 x[i].bi=x[i].ci;
				 x[i].ci=tmp;
			  }
		  }
		  sort(x+1,x+n+1,cmp);
		  for(int i=1;i<=n;i++)
		  {
			  if(f[x[i].ai]<n/2)
			  {
				 f[x[i].ai]++;
				 sum+=x[i].a;
			  }
			  else
			  {
				  f[x[i].bi]++;
				 sum+=x[i].b;
			  }
		  }
		  cout<<sum<<'\n';
	}
	return 0;
}
