#include<bits/stdc++.h>
using namespace stde;
int main()
{
	//	freopen{"polygon.in","r",stdin};
 //	freopen{"polygon.out","w",stdin};
 int n;
 cin>>n;
 int a[n],maxn=-1,sum=0
 for(int i=0;i<n;i++)
 {
 	cin>>a[i]
 }
 if(n==3)
 {
 	for(int i=0;i<n;i++)
 	{
 		maxn=max(maxn,a[i]);
 		sum+=a[i];
	 }
	 if(sum>maxn*2)cout<<i;
	 else cout<<0;
	 return 0;
 }
