#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool flag=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(k==0&&flag==1) cout<<n/2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
