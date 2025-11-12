#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],a0,a1,an,x;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]==0) a0++;
		else if(a[i]==1) a1++;
		else an++;
	}
	if(a1==n)
	{
		if(k==0)
			cout << n/2;
		else if(k==1)
			cout << n;
		else cout << 0;
	}
	else if(an==0)
	{
		if(k==0)
		{
			for(int i=1;i<n;i++)
				if(a[i]==1&&a[i+1]==1)
					x++,i++;
			x+=a0;
			cout << x;
		}
		else if(k==1)
			cout << a1;
		else cout << 0;
	}
	return 0;
}
