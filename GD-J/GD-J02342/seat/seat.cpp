#include<bits/stdc++.h>
using namespace std;
int n,m,ai[110],r,x;
int cmp(int a,int b) 
{
	return a>b;
}
int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>ai[i];
	r=ai[1];
	sort(ai+1,ai+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) if(ai[i]==r) {x=i;break;}
	if(x%n==0) 
	{
		if((x/n)%2)
			printf("%d %d",x/n,n);
		else
			printf("%d %d",x/n,1); 
	}
	else
	{
		if((x/n+1)%2)
			printf("%d %d",x/n+1,x%n);
		else
			printf("%d %d",x/n+1,n-x%n);
	}
	return 0; 
}
