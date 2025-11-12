#include<bits/stdc++.h>
using namespace std;
const int N=11;
bool cmp(int a,int b){return a>b;}
int n,m,g[N*N],s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&g[i]);
	s=g[1];
	sort(g+1,g+n*m+1,cmp);
	bool flag=0;
	int i=1,j=1;
	for(int k=1;k<=n*m;k++)
	{
		if(g[k]==s)
		{
		   printf("%d %d",i,j);
		   break;	
		}
		if((j==1&&flag)||(j==n&&!flag))
		{
			i++;
			flag=!flag;
			continue;
		}
		if(!flag)j++;
		else j--;
	}
	return 0;
}
