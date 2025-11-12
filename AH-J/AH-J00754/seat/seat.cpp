#include <bits/stdc++.h>
using namespace std;
int score[10010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,weizi;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	    scanf("%d",&score[i]);
	int R=score[1];
	sort(score+1,score+n*m+1);
	for (int i=1;i<=n*m;i++)
	    if (score[i]==R)
	    {
			weizi=n*m-i+1;
			break;
		}
	int k=1,x=1,y=1;
	if (k==weizi)
	{
		cout<<1<<" "<<1;
		return 0;
	} 
	while (1)
	{
		while (x%2==1&&y<=n) 
		{
			k++;y++;
			if (k==weizi) 
			{
				cout<<x<<" "<<y;
				return 0;
			}
			if (y==n) 
			{
				k++;x++;
				if (k==weizi) 
			    {
					cout<<x<<" "<<y;
					return 0;
				}
				break;
			}
		}
		while (x%2==0&&y>=1)
		{
			k++;y--;
			if (k==weizi)
			{
				cout<<x<<" "<<y;
				return 0;
			}
			if (y==1)
			{
				k++;x++;
				if (k==weizi) 
				{
					cout<<x<<" "<<y;
					return 0;
				}
				break;
			}
		}
	}
	return 0;
}
