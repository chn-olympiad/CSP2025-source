#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
//		cout<<b[i];
	}
	int lasti=0,lastj=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{	
			if((b[i]^b[j])==k&&(j>lastj)&&(j+1>lasti)&&(i>lasti))
			{
				lastj=j;
				lasti=i;
//				cout<<i<<" "<<j+1<<' '<<(b[i]^b[j])<<endl; 
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
