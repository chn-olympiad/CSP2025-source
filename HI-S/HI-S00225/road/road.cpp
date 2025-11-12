#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,i,j,k,u,v,w,min;
	cin>>n>>m>>k;
	if(1<=i<=m)
		cin>>i;
	if(1<=j<=k)
		cin>>j;
	char c[i],a[j];
	for(i=1;i<=n;i++)
	{
		k=c[i]*j;
		u=a[j]*i;
		min=k+u; 
		min++:
	}
	if(min>=0)
		cout<<min<<endl;
	else
		return 0;
}
