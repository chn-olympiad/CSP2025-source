#include <bits/stdc++.h>
using namespace std;

int n,m,R;
int a[110];

bool cmp(int a,int b){return a>b;}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			int c=ceil(i*1.0/n);
			if(c%2==1)
			{
				cout<<c<<" "<<i-(c-1)*n<<endl;
				break;
			}
			else
			{
				cout<<c<<" "<<n+1-(i-(c-1)*n)<<endl;
				break;
			}
		}
	}
	
	return 0;
}
