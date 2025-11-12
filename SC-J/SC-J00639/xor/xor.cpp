#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int sor[500005];
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sor[i]=sor[i-1]^a[i];
		//cout<<sor[i]<<" "<<i<<endl;
	}
	int nowl=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=nowl;j--)
		{
			if((sor[i]^sor[j-1])==k)
			{
				//cout<<i<<" "<<j<<" "<<sor[i]<<" "<<sor[j-1]<<" "<<(sor[i]^sor[j-1])<<endl;
				nowl=i+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}