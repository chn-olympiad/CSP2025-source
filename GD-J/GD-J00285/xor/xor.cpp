#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],cnt,last_i = 1;
bool find1(int i1,int j1,bool b1)
{
	for(int i = i1;i < j1;i++)
	{
		b1 = 1;
		for(int j = i + 1;j <= j1;j++)
		{
			if((b[j] ^ b[i - 1]) == k)
			{
				if((find1(i,j - 1,1))) cnt++;
				i = j;
				b1 = 0;
				break;
			}
		}
	}
	return b1;
} 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	b[0] = 0;
	b[1] = a[1];
	for(int i = 2;i <= n;i++) b[i] = a[i] ^ b[i - 1];
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == k)
		{
			if(last_i < i - 1) find1(last_i,i - 1,1);
			last_i = i + 1;
			cnt++;
		}
	}
	if(last_i < n) find1(last_i,n,1);
	printf("%d",cnt);
	return 0;
}
