#include<bits/stdc++.h>
using namespace std;
int r=0;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);	
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m,a[101],board[11][11],cnt=0;
	cin>>n>>m;
	int sum=n*m;
	for(int i=0;i<sum;i++)
	{
		cin>>a[i];
	}
	r=a[0];
	for(int i=0;i<sum;i++)
	{
		for(int j=0;j<sum-1;j++)
		{
			if(a[j]<a[j+1])
			{
				int l=a[j];
				a[j]=a[j+1];
				a[j+1]=l;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>0;j--)
			{
				board[i][j]=a[cnt];
				cnt++;
			}
		}
		else if(i%2!=0)
		{
			for(int j=0;j<n;j++)
			{
				board[i][j]=a[cnt];
				cnt++;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[j][i]==r)
			{
				cout<<i+1<<" "<<j+1<<endl;
				break;
			}
		}
	}
	return 0;
}
