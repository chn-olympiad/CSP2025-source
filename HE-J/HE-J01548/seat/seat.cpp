#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll score[1005];
ll m,n;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll seat[n][m];
	for(ll i=0;i<n*m;i++)
	{
		cin>>score[i];
	}
	ll mscore=score[0];
	sort(score,score+(n*m),greater<int>());
	ll cnt=0;
	for(ll i=0;i<m;i++)
	{
		if(i%2==0)
		{
			for(ll j=0;j<n;j++)
			{
				seat[j][i]=score[cnt];
				cnt++;
			}
		}
		else
		{
			for(ll j=n-1;j>=0;j--)
			{
				seat[j][i]=score[cnt];
				cnt++;
			}
		}
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			if(seat[i][j]==mscore)
			{
				cout<<j+1<<" "<<i+1;
				return 0;
			} 
		}
	}
	return 0;
}
