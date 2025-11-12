#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in.txt","r",stdin);
	freopen("xor.out.txt","w",stdout);
	int a[101],n,s=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	int max=-9999;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>max) max=a[i];
	}
	int m;
	if(a[1]<a[2]+a[3]&&(a[1]>a[2]-a[3]||a[1]>a[3]-a[2])) m=3;
	for(int i=1;i<=n;i++)
	{
		if(m>=3&&s>2*max) sum++;
	}
	cout<<sum<<endl;
} 