#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100005][10];
long long f[100005][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		memset(f,0,sizeof(f));
		
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld %lld %lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		
		for(int i=1;i<=n;i++)
		{
			if(i<=n/2)
			{
				f[i][1]=max(f[i-1][1],max(f[i-1][2],f[i-1][3]))+a[i][1];
				f[i][2]=max(f[i-1][1],max(f[i-1][2],f[i-1][3]))+a[i][2];
				f[i][3]=max(f[i-1][1],max(f[i-1][2],f[i-1][3]))+a[i][3];
			}
			else
			{
				f[i][1]=max(f[i-1][2],f[i-1][3])+a[i][1];
				f[i][2]=max(f[i-1][1],f[i-1][3])+a[i][2];
				f[i][3]=max(f[i-1][1],f[i-1][2])+a[i][3];
			}
		}
		printf("%lld\n", max(f[n][1],max(f[n][2],f[n][3])) );
		
		/*
		cout<<"~_~\n";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cout<<f[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
		*/
	}
	return 0;
}
//dp
//3 4 4 2 1 3  2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 1 0 9 8 4 0 0
