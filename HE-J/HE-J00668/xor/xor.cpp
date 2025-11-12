#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,f,h=0,i;
	int a[100001]={0};
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==m) f=a[i];
	}
	for(i=1;i<=n;i++)
	{
		h=h^a[i];
	}
	cout<<abs(h-f);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
