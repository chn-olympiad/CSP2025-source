#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1001];
int little,sum,num;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int j = 0;j <= n*m;j++)
	{
		cin>>a[1];
	}
	little = a[1];
	int minn = 10002,people=-99998;
	for(int i = 0;i <= n*m;i++)
	{
		if(little == a[i])
		{
			cout<<"1"<<n*m-i+1<<endl;
			return 0;
		}
		minn = min(a[i],minn);
	}
	cout<<minn;
	
	return 0;
}