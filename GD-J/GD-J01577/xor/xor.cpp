#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1919810],ans=0,sum=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		ans=a[i];
		for(int j=i;j<=n;++j)
		{
			if(j==i)
			{
				if(k==a[i]){++sum;break;}
				else continue;
			}
			if((a[j]^ans)==k){/*printf("(%d,%d)\n",i,j),*/++sum,i=j;break;}
			ans=a[j]^ans;
			//cout<<ans<<'\n';
		}
	}
	cout<<sum;
	return 0;
}
/*
请给我点分，谢谢。 
I love CCF.
//freopen("xor.in","r",stdin);
//freopen("xor.out","w",stdout);
*/
