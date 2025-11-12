#include<bits/stdc++.h>
#include<cmath>
#include<algorithm> 
using namespace std;
int a[5002];
long long n;
int sso(int m,int su,int b,int dq)
{
	if(dq>n)
	{
		return 0;
	}
	else if(m>=3&&su>2*b)
	{
		return 1+sso(m+1,su+a[dq],max(b,a[dq]),dq+1)+sso(m,su,b,dq+1);
	}
	return sso(m+1,su+a[dq],max(b,a[dq]),dq+1)+sso(m,su,b,dq+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<((sso(0,0,0,0)%998)%244)%353-2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
