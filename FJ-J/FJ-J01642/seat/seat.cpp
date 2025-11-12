#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m;
struct candidate
{
	int sco,id;
}cand[N*N];
bool cmp(candidate a,candidate b){return a.sco>b.sco;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n*m; i++)
	{
		scanf("%d",&cand[i].sco);
		cand[i].id=i;
	}
	int r=cand[1].sco;
	sort(cand+1,cand+n*m+1,cmp);
	if(cand[1].sco==r && cand[1].id==1)
	{
		printf("1 1");
		return 0;
	}
	int x=1,y=1,dir=0,stu=1;
	while(x>=1 && x<=n && y>=1 && y<=m)
	{
		if(cand[stu].sco==r && cand[stu].id==1)
		{
			printf("%d %d",y,x);
			return 0;
		}
		stu++;
		if(x==1 && dir==1 || x==n && dir==0) y++,dir^=1;
		else x+=(dir==0? 1:-1);
	} 
	return 0;
}
