#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[i]+=(a[i-1] xor x);
	}
	int cnt=0;
	int l=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j>=l;j--)
		{
			if ((a[i] xor a[j-1])==k)
			{
				cnt++;
				l=i+1;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
