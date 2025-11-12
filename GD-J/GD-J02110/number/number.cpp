#include<bits/stdc++.h> 
using namespace std;
int cnt[10];
char c;
int main()
{
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	c=getchar();
	while(!isalnum(c)) c=getchar();
	while(isalnum(c))
	{
		if(isdigit(c)) cnt[c&15]++;
		c=getchar();
	}
	for(int i=9;i>=0;i--) while(cnt[i]--) putchar(i^48);
}
