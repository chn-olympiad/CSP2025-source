#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010],b[100010],ma1,ma2;
void copy()
{
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i];
	}
	return;
}
int between(int ii,int s)
{
	for(int i=ii;i<=n;i++)
	{
		if(i!=ii)b[i]=b[i] xor b[i-1];
		if(b[i]==k)
		{
			return between(i+1,s+1);
		}
	}
	return s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)ma2++;
	}
	for(int i=1;i<=n;i++)
	{
		copy();
		ma1=max(ma1,between(i,0));
	}
	cout<<max(ma1,ma2);
	return 0;
}
//过样例1~4 共6个样例 
