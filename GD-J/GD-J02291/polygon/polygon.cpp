#include<iostream>
#include<algorithm>

using namespace std;
const int N=5005;
int n,a[N],f[N],sum=0;

void xyh(int w,int s)
{
	if(w>n+1) return ;
//	printf("%d %d \n",w,s);
	if(w>=3&&a[w-1]*2<s) 
	{
		sum=(sum+1)%998244353;
	}
	for(int i=w;i<=n;i++)
	{
		xyh(i+1,s+a[i]);
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
	sort(a+1,a+1+n);
	xyh(1,0);
	cout<<sum;
	return 0;
}
