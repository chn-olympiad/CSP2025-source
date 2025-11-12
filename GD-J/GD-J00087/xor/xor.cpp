#include<bits/stdc++.h>
using namespace std;
long long n,k,r[500005],ans,ma,num;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	//a xor b
	for(int i=1;i<=n;i++)scanf("%lld",&r[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=ma+1;j<=i;j++)
		{
			num=0;
			for(int k=j;k<=i;k++)
			{
				num=num xor r[k];
			}
			if(num==k)
			{
				ans++,ma=i;
				break;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
//预计得分：<=50
//最多12个样例(60) 
