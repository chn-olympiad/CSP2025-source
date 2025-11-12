#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	for(int i=0;i<=n*m-1;i++)
	  cin>>a[i];
	int r=a[0];
	sort(a+0,a+1+(n*m-1));
	int vis;
	for(int i=0;i<=n*m-1;i++)
	  if(a[i]==r)
	  {
	  	vis=i;
	  	break;
	  }
	vis=n*m-vis-1;
	cout<<vis/n+1<<" ";
	if((vis/n+1)%2==0)
	  cout<<n-vis%n;
	else
	  cout<<vis%n+1;
}