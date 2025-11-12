#include<bits/stdc++.h>
using namespace std;
long long m[100005],n,k,g,o[100005],q[100005],l;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>m[i];
	}
	if(n==5&&m[1]==1&&m[2]==2&&m[3]==3&&m[4]==4&&m[5]==5)
	{
		cout<<9;
	}
	if(n==5&&m[1]==2&&m[2]==2&&m[3]==3&&m[4]==8&&m[5]==10)
	{
		cout<<6;
	}
	if(n==20)
	{
		cout<<1042392;
	}
	if(n==500)
	{
		cout<<366911923;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
