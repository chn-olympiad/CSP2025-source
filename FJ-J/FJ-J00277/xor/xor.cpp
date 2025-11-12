#include<bits/stdc++.h>
using namespace std;
int x,r,t,a[500005],sum;
int main()
{
	//°´Î»Òì»ò:^ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>x>>r;
	for(int i=1;i<=x;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=x;i++)
	{
		sum^=a[i];
		//cout<<sum<<" "; 
		if(sum==r)
		{
			t++;
			sum=0;
			continue;
		}
	}
	cout<<t;
	return 0;
}
