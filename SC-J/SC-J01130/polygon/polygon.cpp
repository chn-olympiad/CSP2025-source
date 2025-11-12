#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,a[N],b[N];
int h;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		    if(a[i]>a[j])
		        swap(a[i],a[j]);
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<i-1;j++)
		{
			if(a[j]+a[j+1]>a[i]*2)
			    h+=(i-j)*(i-j-1)/2;
		}
		
	}
	cout<<h;
	return 0;
} 