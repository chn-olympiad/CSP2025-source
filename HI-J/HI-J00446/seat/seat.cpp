#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b=n*m;
	int R;
	cin>>R;
	for(int i=0;i<n*m;i++)
	{
		int b[i];
		cin>>b[i];
		if(n==1&&m==1)
		{
			if(R>b[i])
			{
				cout<<m<<" "<<n<<endl;
				break;
			}
		}
		if(R>b[i])
		{
			cout<<1<<" "<<1;
			break;
		}
		else
		{
			if(n>=1+1&&m>=1+1)
			{
				cout<<1<<" "<<n-n+1;
				break;
			}
			else
			{
				cout<<2<<" "<<n;
				break;
			}
		}
	}
	return 0;
}
