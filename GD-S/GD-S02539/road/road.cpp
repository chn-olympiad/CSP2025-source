#include <bits/stdc++.h>
using namespace std;	
int n,m,k;
int city[3][1000006],w[1000006];
int a[20][10004];
int c[10004];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(int i =1;i<=m;i++)
	{
		cin>>city[1][i]>>city[2][i];
		cin>>w[i];
	}
	for(int i = 1;i<=k;i++)
	{
		cin>>c[i];
		for(int j =1;j<=n;j++)
		{
			
			cin>>a[i][j];
		}
	}
	bool A = true;
	for(int i = 1;i<=k;i++)
	{
		if(c[i]!=0)
		{
			A=false;
			break;
		}
	}
	if(k==0){
		sort(w+1,w+n+1);
		int ans = 0;
		while(--n)
		{
			ans+=w[n];
		}
		}
	
	return 0;
}
