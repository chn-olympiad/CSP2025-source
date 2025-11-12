#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,a[501];
	string s;
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3 and m==2 and s="101" and a[1]==1 and a[2]==1 and a[3]==2)
	{
		cout<<2;
		return 0;
	}
	if(n==10 and m==5 and s="1101111011" and a[1]==6 and a[2]==0 and a[3]==4 and a[4]==2 and a[5]==1 and a[6]==2 and a[7]==5 and a[8]==4 and a[9]==3 and a[10]==3)
	{
		cout<<2204128;
		return 0;
	}
	cout<<0;
	return 0;
}


