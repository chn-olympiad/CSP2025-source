#include<bits/stdc++.h>
using namespace std;
const int N=550;
int n,m;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	int c[n+2]={};
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=i;
	}
	printf("%d",sum%998%244%353);
	return 0;
}
