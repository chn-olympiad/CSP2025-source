#include <bits/stdc++.h>
using namespace std;

int n,m,a1;
int arr[100010];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>arr[i];
	}
	a1=arr[1];
	sort(arr+1,arr+(n*m)+1);
	for(int i=1;i<=n*m;i++)
	{
		//cout<<arr[i];
		if(arr[i]==a1)
		{
			int x=(n*m-i)/n;
			int y=0;
			if(x%2==0)
			{
				y=(n*m-i+1)-m*(x);
			}else
			{
				y=-(n*m-i+1)+m*(x+1)+1;
			}
			cout<<x+1<<' '<<y;
			//cout<<' '<<(n*m-i+1);
			break;
		}
	}
	return 0;
}
