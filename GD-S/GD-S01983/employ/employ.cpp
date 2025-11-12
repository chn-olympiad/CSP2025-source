#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int m,n,h[505],c[505];
char s[505];
int main()
{
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i = 1;i <= n;i++)
	{
		h[i] = s[i] - '0';	
		printf("%d",&c[i]);
	} 
	printf("%d",n);
	return 0;
}

