#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct nx
{
	int num,pd;
}a[500010];
int n,k,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num;
		a[i].pd=1;
		if(a[i].num==k)	{ans++;a[i].pd=0;}
	}
	cout<<ans;
	/*int sum=0,b[500010]={},s=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].pd==1)	{sum+=a[i].num;b[++s]=i;}
		if(sum==k)
		{	
			ans++;
			for(int i=1;i<=n;i++}
			{
				a[b[s]].pd=0;
			}
		}
	}
	cout<<ans;*/
	return 0;
}
