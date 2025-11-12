#include<iostream>
using namespace std;
int a[500005]={0};
int b[10005][10005]={{1,3,2,4,4,7},
					 {3,2,5,7,7,4},
					 {2,5,3,6,6,5},
					 {4,7,6,4,3,2},
					 {4,7,6,3,5,3},
					 {7,4,5,2,3,6}};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int t=i;
			for(int k=i;k<=j;k++) 
			{
				t=b[a[t]][a[k]];
			}
			if(t==k) ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

