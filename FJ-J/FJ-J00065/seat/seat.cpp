#include <iostream>
#include <algorithm>
using namespace std;

int arr[105];
bool vis[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>arr[i];
	}
	int now=arr[1];
	sort(arr+1,arr+n*m+1,greater<int>());
	int x=1,y=1,cnt=1;
	while(arr[cnt]!=now)
	{
		if(y&1)
		{
			x++;
			if(x>n)
			{
				x=n;
				y++;
			}
		}else
		{
			x--;
			if(!x)
			{
				x=1;
				y++;
			}
		}
		cnt++;
	}
	cout<<y<<' '<<x;
	return 0;
}
