#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int>mp;
int n,k,a,aa,sum=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	mp[0]=sum;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		aa=aa^a;
		if(mp[k^aa]==sum)
		{
			sum++;
			aa=0;
		}
		mp[aa]=sum;
	}sum--;
	cout<<sum;
	return 0;
}
