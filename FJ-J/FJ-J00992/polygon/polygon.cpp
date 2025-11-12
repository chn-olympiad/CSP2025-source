#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],m,n;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	if(n==3)
	{
		cin>>a[1]>>a[2]>>a[3];
		for(int i=1;i<=3;i++)
			m=max(a[i],a[i+1]);
		if(a[1]+a[2]+a[3]>m*2)
			cout<<"1";
		else
			cout<<"0";
		return 0;
	}
	cout<<'0';
		
	return 0;
}
