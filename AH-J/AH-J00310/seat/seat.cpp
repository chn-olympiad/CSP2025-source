#include<bits/stdc++.h>

using namespace std;

int main()
{

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i;
	int x;
	cin>>x;
	int up=0;
	for(i=2;i<=n*m;i++)
	{
		int tmp;
		cin>>tmp;
		if(tmp>x)
		{
			up++;
		}
	}
	//cout<<"UP="<<up<<endl;
	cout<<(up/n+1)<<" ";
	if((up/n+1)%2==0)
	{
		cout<<(n-(up%n))<<endl;
	}
	else
	{
		cout<<(up%n+1)<<endl;
	}

	return 0;
}
