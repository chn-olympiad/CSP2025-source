#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,fi = 0,se = 0,th = 0,adj[N][5];
		cin>>n;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=3;j++)
			{
				cin>>adj[i][j];
			}
		}
		int a[N],b[N];
		for(int i = 1;i<=n;i++)
		{
			if(adj[i][1]>adj[i][2])
			{
				a[i] = adj[i][1];
				b[i] = adj[i][1] - adj[i][2];
			}
			else
			{
				a[i] = adj[i][2];
				b[i] = adj[i][2] - adj[i][1];
			}
		}
		sort(b+1,b+n+1);
		int cnt = 0,mid = n/2,num = 0;
		for(int i = 1;i<=n;i++){
			cnt+=a[i];
			num++;
		}
		if(num>mid)
		{
			int m = num - mid;
			for(int i = 1;i<=m;i++){
				cnt-=b[i];
			}
			cout<<cnt<<endl;
		}
		else
		{
			cout<<cnt<<endl;
		}
	}
	return 0;
}

