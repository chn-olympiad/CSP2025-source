#include<bits/stdc++.h>
using namespace std;
bool b[100000];
int a[100000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int total=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);//cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int s=a[i];
		for(int j=i-1;j>=1;j--)
		{
			s+=a[j]&s;
		}
		if(s==k) total++;
		for(int j=i+1;j<=n;j++)
		{
			s+=a[j]&s;
		}
		if(s==k) total++;
	}
	cout<<total;
	return 0;
}
