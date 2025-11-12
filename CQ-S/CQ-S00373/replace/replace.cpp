#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N = 2e5 + 5;
const int M = 5e6 + 5;
const int P = 37;

ull pre[N],suf[N],must[2][N];
int zuo[N],you[N];
int n,q;
char str1[M],str2[M];
ull fstpw[M];
ull ha[2][M];
ull hashi(char* str,int l,int r,int type)
{
	ull ans = 0;
	if(type == 1)
	{
		for(int i = l;i <= r;i++)
			ans += fstpw[i - l] * (str[i] - 'a' + 1);		
	}
	else
	{
		for(int i = r;i >= l;i--)
			ans += fstpw[r - i] * (str[i] - 'a' + 1);
	}
	return ans;
}
int main(void)
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	fstpw[0] = 1;
	for(int i = 1;i <= M - 2;i++)
		fstpw[i] = fstpw[i - 1] * P;
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++)
	{
		scanf("%s%s",str1 + 1,str2 + 1);
		int len = strlen(str1 + 1);
//		printf("len = %d\n",len);
		int a = 1;
		while(a <= len && str1[a] == str2[a])
			a++;
		if(a == len + 1)
		{
			pre[i] = suf[i] = P - 2;
			continue;
		}
		int b = len;
		while(str1[b] == str2[b])
			b--;
		must[0][i] = hashi(str1,a,b,1);
		must[1][i] = hashi(str2,a,b,1);
		pre[i] = hashi(str1,1,a - 1,2);
		suf[i] = hashi(str1,b + 1,len,1);
		zuo[i] = a - 1;
		you[i] = len - b;
//		printf("## %d %d %llu %llu %llu %llu\n",zuo[i],you[i],pre[i],suf[i],must[0][i],must[1][i]);
	}
	while(q--)
	{
		scanf("%s",str1 + 1);
		scanf("%s",str2 + 1);
		if(strlen(str1 + 1) != strlen(str2 + 1))
		{
			printf("0\n");
			continue;
		}
		int len = strlen(str1 + 1);
		int a = 1;
		while(str1[a] == str2[a])
			a++;
		int b = len;
		while(str1[b] == str2[b])
			b--;
		for(int i = 0;i <= len + 1;i++)
			ha[0][i] = ha[1][i] = 0;
		for(int i = a - 1;i >= 1;i--)
		{
			ha[0][i] = ha[0][i + 1] + fstpw[a - 1 - i] * (str1[i] - 'a' + 1);
//			printf("ha[0][%d] = %lld\n",i,ha[0][i]);
		}
		for(int i = b + 1;i <= len;i++)
		{
			ha[1][i] = ha[1][i - 1] + fstpw[i - (b + 1)] * (str1[i] - 'a' + 1);
//			printf("ha[1][%d] = %lld\n",i,ha[1][i]);
		}
		ull r1 = hashi(str1,a,b,1);
		ull r2 = hashi(str2,a,b,1);
//		printf("rer %lld %lld %lld %lld\n",r1,r2,a,b);
		a--;
		b++;
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(pre[i] == P - 2)
				continue;
			if(zuo[i] <= a && ha[0][a - zuo[i] + 1] == pre[i] && b + you[i] - 1 <= len && ha[1][b + you[i] - 1] == suf[i] && must[0][i] == r1 && must[1][i] == r2)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
