#include<bits/stdc++.h>
using namespace std;
struct tutu{
	int a;
	int b;
	int c;
}tu[1000005];
int zu[1000005];
bool cmp(tutu x,tutu y)
{
	return x.c<y.c;
}
int find(int x){
	if(zu[x]==x)
	return zu[x];
	else
	{
		zu[x]=find(zu[x]);
	}
	return zu[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long fei=0;
 	for(int i=1;i<=m;i++)
 	cin>>tu[i].a>>tu[i].b>>tu[i].c;
	sort(tu+1,tu+n+1,cmp);
	for(int i=1;i<=n;i++)
	zu[i]=i;
	int bian=0;
	for(int l=1;l<=m;l++)
	{
		int zu1=find(tu[l].a);
		int zu2=find(tu[l].b);
		if(zu1!=zu2)
		{
			bian++;
			zu[zu1]=zu2;
			fei+=tu[l].c;
		}
		
		if(bian==n-1)
		{
			break;
		}
	}
	cout<<fei;
}
