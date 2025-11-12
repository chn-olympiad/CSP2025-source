#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans,cnt=a[1];
//	int ans=a[1];
//	int ans=n*m;
//	for(int i=1;i<=n;i++)
//	{
//		if(i%2==1)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				b[j][i]=a[ans];
//				ans--;
//			}
//		}
//		else
//		{
//			for(int j=m;j>=1;j--)
//			{
//				b[j][i]=a[ans];
//				ans--;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<b[i][j]<<" ";
//		}
//		cout<<"\n";
//	} 
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==cnt)
		{
			ans=n-i+1;
			break;
		}
	}
	if((ans%n)!=0)
	{
		cout<<ans/n+1<<" ";
	}
	else cout<<ans/n<<" ";
	if((ans/n)%2==0)
	{
		cout<<ans%n;
	}
	else cout<<n-(ans%n);
	return 0;
}//#Shang4Shan3Ruo6Shui4
