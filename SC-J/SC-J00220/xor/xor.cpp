#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(k==0)
	{
		int cnt=0,cnt2=0;
		for(int i=1;i<=n;i++)
			if(a[i]==0) cnt++,cnt2=0;
			else
			{
				if(cnt2==1) cnt++,cnt2=0;
				else cnt2++;
			}
		printf("%d\n",cnt);
	}
	else if(k==1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=a[i];
		printf("%d\n",cnt);
	}
	return 0;
}