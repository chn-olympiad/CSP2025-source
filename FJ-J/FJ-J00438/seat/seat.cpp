#include<cstdio>
#include<algorithm>
using namespace std;

int m,n;
int a[110];
int cnt=0;
int rscore,r,rx,ry;

int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);				Æ­£¡
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=n;i++)
	{	for(int k=1;k<=m;k++) 
		{	scanf("%d",&a[cnt]);
			cnt+=1;
		}
	}
	rscore=a[0];
	sort(a,a+cnt);
	
	for(int i=cnt-1;i>=0;i--)
	{
		if(a[i]==rscore)
		{	r=cnt-i;break;	}
	}
	
	if(r%n==0)
	{
		rx=r/n;
		if(rx%2==0) ry=1;
		if(rx%2==1) ry=m;
		printf("%d %d",rx,ry);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	rx=r/n+1;
	
	if( rx%2==1 )
	{	ry=r-(rx-1)*n;	}
	if( rx%2==0 )
	{	ry=n-(r-(rx-1)*n)+1;	}
	printf("%d %d",rx,ry);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

