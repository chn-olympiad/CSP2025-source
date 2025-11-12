#include<bits/stdc++.h>
using namespace std;
bool Mst;
const int N=2e6+10;
int n;
char s[N];
int cnt[1010];

bool Med;
signed main()
{
//	cerr<<"Memory:"<<(&Med-&Mst)/1048576.0<<" Mib.\n";
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			putchar(char(i+'0'));
		}
	}
}
/*
number
g++ number.cpp -o number.exe
g++ check.cpp -o check.exe
./number.exe
./check.exe
*/ 
