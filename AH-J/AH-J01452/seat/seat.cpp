#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int fx[4]={0,1,0};
int fy[4]={1,0,-1};
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int r;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,d=0;
	for(int i=1;i<=n*m;i++)
	{
		if(d==0&&y==n)d=1;
		else if(d==1)d=2;
		else if(d==2&&y==1)d=1;
		if(a[i]==r)
		{
			printf("%d %d",x,y);
			break;
		}
		x+=fx[d],y+=fy[d];
	}
	return 0;
}

