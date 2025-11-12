#include <bits/stdc++.h>
using namespace std;
int score[1005];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int R=0;
	for(int i=1;i<=n*m;i++)
		cin>>score[i];
	R=score[1];
	sort(score+1,score+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				cnt++;
				if(score[cnt]==R)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				cnt++;
				if(score[cnt]==R)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}