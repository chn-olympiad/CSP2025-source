#include<bits/stdc++.h>
using namespace std;	
int n,a[100001],l[100001],b[100001];
long long ans=0;
void go(int x,int zhi,int w,int m,int o)
{	
	if(zhi>2*m&&o>=3)
	{
		ans++;
	}
	for(int j=w+1;j<=n;j++)
	{		
		go(a[j],zhi+a[j],j,max(a[j],m),++o);
	}

}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		go(a[i],a[i],i,a[i],1);
	}
	cout<<ans;
	return 0;
}