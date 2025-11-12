#include<bits/stdc++.h>

using namespace std;

long long a[101];
long long Map[101][101];
long long fg(int a,int b)
{
	return a>b;
 } 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int r=a[1];
	sort(a+1,a+(n*m)+1,fg);
	int cnt=1;
	for(int i=1;i<=m;i++)
	{
		bool flag=true;
		if(i%2==1)
			flag=true;
		else if(i%2==0)
			flag=false;
		if(flag==true)
			for(int j=1;j<=n;j++)
			{
				Map[j][i]=a[cnt];
				cnt++;
			}
		else
			for(int j=n;j>=1;j--)
			{
				Map[j][i]=a[cnt];
				cnt++;
			}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<Map[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(Map[i][j]==r)
			{
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
    
	return 0;
 } 
