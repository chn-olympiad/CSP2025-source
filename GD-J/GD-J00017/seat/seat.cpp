#include<cstdio>
using namespace std;
int n,m,s[101],pri,rn,rm;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n*m;i++)
	{
		scanf("%d",&s[i]);
	}
	for(int i=1;i<n*m;i++)
	{
		if(s[i]>s[0])
		{
			pri++;
		}
	}
	rm=(pri/n)+1;
	if(rm%2==0)
	    rn=n+1-((pri+1)-rm*n+n);
	else
	    rn=(pri+1)-rm*n+n;
	printf("%d %d",rm,rn);
}
