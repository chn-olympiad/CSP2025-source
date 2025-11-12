#include<bits/stdc++.h>
using namespace std;
int n,m,h,a[1005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	h=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
	//	cout<<a[i]<<" ";
		if(a[i]==h)
		{
			//cout<<i<<endl;
			if(i%m==0)
			{
				cout<<i/m<<" ";
				if((i/m)%2==1)cout<<m;
				else cout<<1;
			}
			else 
			{
				cout<<i/m+1<<" ";
				if((i/m)%2==0)
				{
					cout<<i%m;
				}
				else cout<<m-i%m+1;
			}
			break;
		}
	}
	return 0;
}
