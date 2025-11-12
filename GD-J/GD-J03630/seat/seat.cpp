#include<bits/stdc++.h>
using namespace std;
int Pts[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int M,N,R,Ansx,Ansy;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M*N;i++)
		scanf("%d",&Pts[i]);
	R=Pts[1];
	sort(Pts+1,Pts+M*N,cmp);
	for(int i=1;i<=M*N;i++)
		if(R==Pts[i])
			R=i;
	Ansx=(R-1)/N+1;
	if(Ansx%2==0)
		Ansy=M+1-(R%N);
	else 
		Ansy=R%N;
	printf("%d %d",Ansx,Ansy);
	return 0;
}
