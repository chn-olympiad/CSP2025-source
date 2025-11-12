#include<bits/stdc++.h>
using namespace std;
bool vis[500010],key;
int n,k,a[500010];
long long sum=0;
int main()
{
	freopen("xor.in" ,"r",stdin );
	freopen("xor.out","w",stdout);
	memset(vis,0,sizeof(vis));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			//cout<<endl<<i<<" "<<j<<":";
			key=true; int x=0;
			for(int v=i;v<=j;v++)
			{
				//cout<<a[v]<<" ";
				if(vis[v]==1) key=false,v=j+1;
				x=x^a[v];
			}
			//cout<<"key:"<<key;
			if(key) 
			{
				if(x==k)
				{
					memset(vis+i,1,j-i+1);
					//cout<<"yes";
					sum++;
				}
			}
		}
	}
	cout<<sum;
}
