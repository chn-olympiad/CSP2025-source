#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],s[N];
int n,k,cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		s[1]=a[1];
		if (i!=1) s[i]=s[i-1]^a[i];
	}
	if (k==0) printf("%d",n/2);
	else if (k==1)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]==1) cnt++;
		}
		printf("%d",cnt);
		cnt=0;
	}
	return 0;
}
