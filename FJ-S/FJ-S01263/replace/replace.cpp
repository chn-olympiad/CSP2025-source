#include<iostream>
#include<cstdio>
using namespace std;
string a[200001],b[200001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(q--)
	{
		string c,d;
		int g=0;
		cin>>c>>d;
		for(int i=1;i<=n;i++)
		{	int p=c.find(a[i]),p2=a[i].size();if(p!=-1){string r=c;for(int j=p;j<p+p2;j++)r[j]=b[i][j-p];if(r==d)g++;}}printf("%d\n",g);}return 0;}
