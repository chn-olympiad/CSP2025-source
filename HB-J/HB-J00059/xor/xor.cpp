#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005],ans;
long long f(int x,int y)
{
	long long num=a[x];
	for(int i=x+1;i<=y;i++)
		num=(num^a[i]);
	return num;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			if(f(l,r)==k)
			{
				ans++;
				l=r+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
