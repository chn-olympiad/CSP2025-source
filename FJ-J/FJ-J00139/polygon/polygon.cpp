#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long t;
void v(int h,int M,int w)
{
	if(a[w]>M)
		M=a[w];
	h+=a[w];
	if(h>2*M)
	{
		t++;
		if(t==998244353)
			t=0;
	}
	if(w==n)
		return ;
	for(int i=w+1;i<=n;i++)
		v(h,M,i);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-2;i++)
		v(0,0,i);
	cout<<t;
	return 0;
}