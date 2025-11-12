#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],f[N],ans,last;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]^=a[i-1];
	}
	f[1]=((a[1]==k)?1:0);
	
	for(int i=2;i<=n;i++)
		for(int j=i;j>=1;j--)
		{
			if((a[i]^a[j-1])==k) f[i]=max(f[i],f[j-1]+1);
			else f[i]=max(f[i],f[j-1]);
		}
	cout<<f[n]<<endl;
	return 0;
}
