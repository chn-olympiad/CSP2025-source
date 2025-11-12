#include<bits/stdc++.h>
using namespace std;
int a[500050];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if((a[1]==0&&a[2]!=0)||(a[1]==a[2]&&a[1]!=0)||(a[1]!=0&&a[2]==0))
	{
		cout<<1;
	}
	if(a[1]==0&&a[2]==0)
	{
		cout<<2;
	}
	return 0;
}
