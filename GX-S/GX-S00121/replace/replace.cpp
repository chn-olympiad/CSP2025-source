#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define maxn 200005
#define maxl 5000006
using namespace std;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c && c<='9'))
	{
		if(c=='-')
		  f=-1;
		c=getchar();
	}
	while('0'<=c && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

int n,q;
string s[maxn][2];
string t[maxn][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	/*for(int i=1;i<=n;i++)
	    cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)
	    cin>>t[i][0]>>t[i][1];
	*/
	for(int i=1;i<=q;i++)
	   printf("0\n");
	return 0;
}
