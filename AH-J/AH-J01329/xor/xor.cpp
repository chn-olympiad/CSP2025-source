#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
long long b[1000001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor,out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int cnt=0;
	int c;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			c=a[i] xor a[j];
			cout<<i<<" "<<j<<" "<<c<<endl;
			if(c==k)
			{
				cnt++;
				break;
			}
		}
	cout<<cnt<<endl;
	return 0;
}
