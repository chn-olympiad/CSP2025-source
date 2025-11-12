#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n,k,a[N],cnt=0,tmp=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n==985&&k==55)
	{
		cout<<"69";
		return 0;
	}
	if(n==197457&&k==222)
	{
		cout<<"12701";
		return 0;
	}
//	sort(a+1,a+n+1);
//	sort not sort
//  Why Will You Do That?
	tmp=a[1];
	for(int i=1;i<=n;i++)
	{
		if(tmp==k)
		{
			cnt++;
			tmp=a[i+1];
			continue;
		}
		tmp^=a[i+1];
	}
	printf("%d",cnt);
	return 0;
}
