#include<bits/stdc++.h>
using ll = long long;
using namespace std;
char s[1000005];
ll vis[10];
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
	scanf("%s",s+1);
	for(int i = 1;i <= strlen(s+1);i++)
		if(s[i] >= '0' && s[i] <= '9')vis[s[i] - '0']++;
	for(int i = 9;i >= 0;i--)
	{
		for(ll j = 1;j <= vis[i];j++)printf("%d",i);
	}
	return 0;
}

