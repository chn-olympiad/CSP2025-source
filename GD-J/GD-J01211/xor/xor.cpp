#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[500007];
long long total;
bool in[500007] , tr;
long long x;
long long head,teil;

int main()
{
	freopen("xor.in", "r" ,stdin);
	freopen("xor.out", "w" ,stdout);
	scanf("%lld%lld",&n,&k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld",&a[i]);
		if(a[i] == k)
		{
			in[i] = 1;
			total++;
		}
	}
	for(int j = 2; j <= n; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			if(n - i < j) break;
//			printf("i = %d j = %d\n",i,j);
			if(in[i] == 1)
			{
				continue;
			}
			head = i;
			teil = i;
//			printf("head = i\n");
			x = a[i];
			while(teil <= n)
			{
				teil++;
				while(in[teil] == 1)
				{
//					printf("in[teil] = 1 head = %d teil = %d x = %d\n",head,teil,x);
					head = teil + 1;
					teil = teil + 1;
					x = a[head];
					if(teil > n) break;
				}
				if(teil > n)
				{
					break;
				}
				while(teil - head + 1 > j)
				{
					x ^= a[head];
					head++;
				}
				x ^= a[teil];
				if(teil - head + 1 < j) continue ;
//				printf("head = %lld teil = %lld x = %lld\n",head,teil,x);
				if(x == k and teil - head + 1 == j)
				{
					for(int l = head; l <= teil ; l++)
					{
						in[l] = 1; 
					}
					total++;
					head = teil + 1;
					teil = teil + 1;
					x = a[head];
				}
			}
		}
	}
	printf("%lld",total);
	return 0;
}
