#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=1e6+10;
ll tong[12],k=1;
char s[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&s[k])!=EOF)
	{
		if(s[k]>='0' && s[k]<='9')  tong[s[k]-'0']++;
		k++;
	}
	for(int i=9;i>=0;i--)
	{
		while(tong[i]--!=0)  printf("%d",i);
	}
	return 0;
}
