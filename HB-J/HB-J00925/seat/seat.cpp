#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
struct node
{
	int mark;
	int id;
}a[1010];
bool cmp(node a,node b)
{
	return a.mark>b.mark;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	const int tot=n*m;
	for(int i=1;i<=tot;i++)
	{
		cin>>a[i].mark;
		a[i].id=i;
	}
	sort(a+1,a+1+tot,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				cnt++;
				if(a[cnt].id==1)
				{
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
			}
		}
		else if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				cnt++;
				if(a[cnt].id==1)
				{
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
			}
		}
	}
}
//Thanks to my dear Mr.Li!
//Killed in 18 mins :)
