#include<bits/stdc++.h>
using namespace std;
long long n,m[100000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>m[i];
	if(n==1||n==2)
	{
		cout<<"0";
		return 0;
	}
	if((m[1]+m[2])>m[3]&&(m[3]+m[2])>m[1]&&(m[1]+m[3])>m[2])
	{
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
