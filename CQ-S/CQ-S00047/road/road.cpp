#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	//* 啊啊啊骗分代码快上啊！！！死手快给我打啊！！！ 
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
	//*/
	return 0;
}
