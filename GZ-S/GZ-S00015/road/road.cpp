//GZ-S00015 贵阳市南明区华麟学校 代钰涵 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10; 
int n,m,k,ldl=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n/2;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		ldl+=w;
	}
	cout<<ldl;
	return 0;
}
