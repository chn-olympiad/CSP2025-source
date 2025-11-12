#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	int a[100001];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==m) sum++;
	}
	cout<<sum+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
