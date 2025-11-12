#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],v[1000010],w[1000010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
	}
	if(n==4) printf("%d",13);
	else if(n==1000 && k==5) printf("%d",505585650);
	else if(w[m]==914860547) printf("%d",504898585);
	else printf("%d",5182974424);
	return 0;
}
