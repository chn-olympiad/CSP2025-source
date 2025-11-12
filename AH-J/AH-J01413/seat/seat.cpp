#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[105];
    int er,pai=1;
	cin>>n>>m;
	cin>>er;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
        if(a[i]>er) pai++;
	}
	if(pai%n==0)
	{
		if(pai/n%2==0)
		{
			cout<<pai/n<<' '<<1;
			return 0;
		}
		else
		{
			cout<<pai/n<<' '<<n;
			return 0;
		}
	}
	else
	{
		if((pai+n)/n%2==0)
		{
			cout<<(pai+n)/n<<' '<<n;
			return 0;
		}
	}
}
