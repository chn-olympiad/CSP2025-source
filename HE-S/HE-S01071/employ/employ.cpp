#include<bits/stdc++.h>
using namespace std;
int n,m;
char d[510];
int c[510],p[510];
int main()
{
	freopen("employ.in","r","stdin");
	freopen("employ.out","r","stdout");
	cin>>n>>m;
	cin>>d;
	int lend=strlen(d);
	for(int i=1;i<=lend;i++)
	{
		c[i]=d[i]-'0';
	}
	return 0;
}
