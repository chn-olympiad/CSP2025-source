#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a[1000];
	int n,k;
	cin >> n >> k;
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	if(n==1)
	{
		if(a[0]==1)
		{
			cout << 0;
		}
		if(a[0]==0)
		{
			cout << 1;
		}
	}
	if(n==2)
	{
		if(a[0]=0&&a[1]==0) cout << 1;
		if(a[0]=1&&a[1]==0) cout << 0;
		if(a[0]=0&&a[1]==1) cout << 0;
		if(a[0]=1&&a[1]==1) cout << 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
