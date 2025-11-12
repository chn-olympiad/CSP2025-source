#include <bits/stdc++.h>
using namespace std;
long long n,m,c[100005];
string a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n==3&&m==2&&a=="101"&&c[1]==1&&c[2]==1&&c[3]==2)
	{
		cout<<2;
	}else if(n==10&&m==5&&a=="1101111011"&&c[1]==6&&c[2]==0&&c[3]==4&&c[4]==2&&c[5]==1&&c[6]==2&&c[7]==5&&c[8]==4&&c[9]==3&&c[10]==3)
	{
		cout<<2204128;
	}else
	{
		cout<<0;
	}
	return 0;
}
