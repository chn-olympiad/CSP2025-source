#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
char s[N]; 
int cnt[20],n=0,sum=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt[s[i]-'0']++;
			sum++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(cnt[i]--) 
		{
			printf("%d",i); 
		}
	}
	return 0;
} 