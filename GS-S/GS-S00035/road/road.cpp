#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k,h[N];
struct s{
	int u,v,w;	
}a[N];
void add(int u,int v,int w)
{

	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&(x,y,z));
		add(x,y,z);
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
}
