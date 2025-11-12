#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,1};
int dy[4]={1,0,-1,0}; 
int a[20][20];
int score[110],R;
bool cmp(int a,int b){return a>b;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&score[i]);
	R=score[1];
	sort(score+1,score+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(score[i]==R)R=i;
	int t=0,x=1,y=1,id=1;
	while(id<=R)
	{
		if(id==R)
		{
			printf("%d %d\n",y,x);
			break;
		}
		id++;
		if(x==n||(x==1||id!=1))
		{
			t++;
		}
		if(t==4)t=0;
		x+=dx[t];
		y+=dy[t]; 
	}
	return 0;
}
