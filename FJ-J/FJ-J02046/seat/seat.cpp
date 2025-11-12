#include <bits/stdc++.h>
using namespace std;
struct ren{
	int chengji=0;
	int shenfen=0;
};
ren a[300];
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i].chengji;
		if(i==0)
		{
			a[i].shenfen=1;
		}
		else
		{
			a[i].shenfen=0;
		}
	}
	for(int i=0;i<n*m;i++)
	{
		for(int k=i;k<n*m;k++)
		{
			if(a[k].chengji>a[i].chengji)
			{
				swap(a[k].chengji,a[i].chengji);
				swap(a[k].shenfen,a[i].shenfen);
			}
		}
	}
	for(int i=0;i<n*m;i++)
	{
		if(a[i].shenfen==1)
		{
			if((i/n)%2==0)
			{
				cout<<(i/n)+1<<" "<<(i%n)+1;
			}
			else
			{
				cout<<(i/n)+1<<" "<<m-(i%n);
			}
			return 0;
		}
	}
	
	return 0;
}
