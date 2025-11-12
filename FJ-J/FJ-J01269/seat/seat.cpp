#include<bits/stdc++.h>
using namespace std;
int n,m,k[150],a1,x[150],y[150],now=0;
bool cmp(int x1,int x2)
{
	return x1>x2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>k[i];
	a1=k[1];
	sort(k+1,k+1+(n*m),cmp);
	for(int i=1;i<=m;i++)
	{
	  if(i%2) for(int j=1;j<=n;j++) x[++now]=i,y[now]=j;
	  else for(int j=n;j>0;j--) x[++now]=i,y[now]=j;
	}
	for(int i=1;i<=n*m;i++)
	  if(k[i]==a1)
	    cout<<x[i]<<" "<<y[i];
	return 0;
}
