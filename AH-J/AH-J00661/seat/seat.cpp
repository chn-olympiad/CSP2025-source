#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
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
	int f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==f)
		{
			if(i%n==0){
				cout<<i/n;
			}
			else{
				cout<<i/n+1;
			}
			if((i/n)%2==1){
				if(i%n==0){
					cout<<m;
				}
				else{
					cout<<i%n;
				}
			}
			else{
				if(i%n==0){
					cout<<1;
				}
				else
				{
					cout<<n-i%n+1;
				}
			}
		}
	}
	return 0;
}
