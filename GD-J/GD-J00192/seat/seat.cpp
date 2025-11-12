#include<bits/stdc++.h>
using namespace std;
int n,m,r,num,lis,seat;
int s[101];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d %d",&n,&m,&s[1]);
	r=s[1];
	for(int i=2;i<=n*m;i++) scanf("%d",&s[i]);
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) 
	  if(s[i]==r) num=i;
	lis=(num-1)/n+1;seat=num%(2*n);
	if(seat>n) seat=2*n-seat+1;
    printf("%d %d",lis,seat);
	return 0;
}

