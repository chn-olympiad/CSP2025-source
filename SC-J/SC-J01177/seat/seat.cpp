#include<bits/stdc++.h>
using namespace std;
int a[10005];
int b[10005][10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nm;
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++)
	{
		cin>>a[i];
	}
	int a0=a[1];
	sort(a+1,a+nm+1);
	int tot=nm+1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
		    {
			    tot--;
			    b[i][j]=a[tot];
//		        cout<<b[i][j]<<" ";
			    if(b[i][j]==a0)
			    {
				    cout<<i<<" "<<j;
				    return 0;
			    }
		    }
		}
		else
		{
			for(int j=1;j<=n;j++)
		    {
			    tot--;
			    b[i][j]=a[tot];
//			    cout<<b[i][j]<<" ";
			    if(b[i][j]==a0)
			    {
				    cout<<i<<" "<<j;
				    return 0;
			    }
		    }
		}
	}
	return 0;
}