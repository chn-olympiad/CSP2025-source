#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s[5010],c;
bool pd(int l,int r)
{
	if(s[r-1]-s[l-1]>a[r]) return 1;
	return 0;
}
int main()
{
    freopen("polgon.in","r",stdin);
    freopen("polgon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
		s[i]=a[i]+s[i-1];
	}
    for(int i=2;i<=n;i++)
    {
		for(int j=1;j<=n-i+1;j++)
		{
			if(pd(j,i+j-1)) c++;
		}
	}
	cout<<c;
    return 0;
}
