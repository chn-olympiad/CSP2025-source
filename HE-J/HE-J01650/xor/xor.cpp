#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,pos=0;
	cin >>n >>k;
	int a[n+1]={},yh[n+1]={1};
	bool f[n+1]={};
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
		if(a[i]==k)
		{
			pos++;
			f[i]=1;
		}
		else
		{
			yh[i]=yh[i-1]^a[i];
			if(yh[i]==k)
				pos++;
		}
	}
	cout <<pos;
	return 0;
}
