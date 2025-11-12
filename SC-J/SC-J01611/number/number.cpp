#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e6;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[maxn],n[maxn],max;
	memset(n,0,sizeof(n));
	int num=-1;
	scanf("%s",s);
	for(int i=0;i<strlen(s);++i)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num++;
			n[num]=s[i];
		}
	}
	sort(n,n+num+1);
	for(int i=num;i>=0;--i)
	{
		printf("%c",n[i]);
	}
	return 0;
} 