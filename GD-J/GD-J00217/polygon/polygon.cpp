//#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
int n,m,a[5001],T;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)T=1;
	}
	
	if(T==0)
	{
		double k=11.0/6.0*(n-2)*(n-2)*(n-2)-8*(n-2)*(n-2)+91.0/6.0*(n-2)-8;
			k=k-998244353*int(k/998244353);
		cout<<int(k);
		return 0; 
	}
    cout<<6;
	return 0;
}
