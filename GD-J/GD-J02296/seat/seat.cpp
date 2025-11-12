#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m,a[MAXN],q,a1,xx,yy,s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==a1){
			q=i;
			break;
		}
	yy=q/n;
	if(q%n>0)		//列 
		yy++;
	
	if(q%n==0)
		s=n;
	else s=q%n;
	if(yy%2==1)		//单数行从前到后 
		xx=s;
	else			 
		xx=n-s+1;
	printf("%d %d",yy,xx);
	return 0;
}
