#include<bits/stdc++.h>
using namespace std;
int n,m,sc[105],a;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>sc[i];
	}
	a=sc[1];
	int x=1,y=1;
	sort(sc+1,sc+n*m+1,cmp);
	int i=1;
	while(a!=sc[i])
	{
		if((y==n&&x%2==1)||(y==1&&x%2==0)) x++;
		else if(x%2==1) y++;
		else y--;
		i++;
	}
	cout<<x<<" "<<y;
}
