#include<bits/stdc++.h>
using namespace std;
int n,m,Rt,et,bt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Rt);
	for(int i=0;i<n*m-1;i++)
	{
		scanf("%d",&et);
		if(et>Rt) bt++;
	}
	bt++;
	cout<<((bt-1)/m)+1<<" ";
	if((((bt-1)/m)+1)%2==0) cout<<n-((bt%m==0)?m:bt%m)+1;
	else 
	{
		if(bt%m==0) cout<<m;
		else cout<<bt%m;
	}
	return 0;
 } 
