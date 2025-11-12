//Great thanks to Dr.Xiong again!
//Are you the same teacher as the first question?
//-Yes,I am.
//-No,I'm not.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll score[105];
ll seat[10][10];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	//question needed
	ll a;
	//size of the classroom
	ll x;
	//score of R
	ll k;
	//for place change
	cin>>n>>m;
	a=n*m;
	cin>>x;
	for(int i=2;i<a;i++)
		cin>>score[i];
	score[1]=x;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(score[i]<score[j] and i<j)
			{
				k=score[i];
				score[i]=score[j];
				score[j]=k;
			}
		}
	}
	for(int l=1;l<n;l++)
	{
		for(int i=1;i<=a;i++)
		{
			if(i<=n)
				seat[1][i]=score[i];
			else if((i-l)%n==0)
			{
				if(l%2!=0)
					seat[(i-l)%n][l]=score[i];
				else
					seat[n-(i-l)%n][l]=score[i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(seat[i][j]==x)
			{
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}
