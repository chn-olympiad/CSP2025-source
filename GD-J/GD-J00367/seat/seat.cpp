#include <bits/stdc++.h> //2
using namespace std;

int n,m,a[105];
int ans; //a装数,b装座位号 

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	ans=a[1];
	
	sort(a+1,a+n*m+1,cmp);
	
	int i=0,x=0,y=1;
	while (i<=n*m)
	{
		i++;
		if (y&1)
		{
			x++;
			if (x>n)
			{
				y++;
				x=n;
				
//				cout<<"i="<<i<<' '<<"x="<<x<<"y="<<y<<endl;
			}
//			else cout<<"i="<<i<<' '<<"x="<<x<<"y="<<y<<endl;
		}
		else
		{
			x--;
			if (x<1)
			{
				y++;
				x=1;
				
//				cout<<"i="<<i<<' '<<"x="<<x<<"y="<<y<<endl;
			}
//			else cout<<"i="<<i<<' '<<"x="<<x<<"y="<<y<<endl;
		}
		
		if (a[i]==ans)
		{
			cout<<y<<' '<<x;
			return 0;
		}
	}
	return 0;
 } 
