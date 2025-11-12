#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
struct player
{
	int score,id;
}mp[105];
bool cmd(player a,player b)
{
	return a.score>b.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>mp[i].score;
		mp[i].id=i;
	}
	sort(mp+1,mp+1+n*m,cmd);
	for(int i=1;i<=n*m;i++)
	{
		if(mp[i].id==1)
		{
			x=i%n?i/n+1:i/n;
			y=x%2?i-(x-1)*n:n+1-(i-(x-1)*n);
			cout<<x<<' '<<y;
			break;
		}
	}
	return 0;
}
//999999999999999999999999999