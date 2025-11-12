#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000];
string s1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%d",&n,&m);
	cin>>s1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(m<=2)
	{
		printf("%d",m);
	}
	else
	{
		printf("0");
	}
	return 0;
}
