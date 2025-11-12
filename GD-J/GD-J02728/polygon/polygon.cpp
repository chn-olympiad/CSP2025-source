#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon1.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum=0;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3)
	{
		if(a[0]+a[1]>a[2] && a[0]+a[2]>a[1] && a[1]+a[2]>a[0])
		{
			sum++;
		}
	}

	cout<<sum;
    return 0;
}
