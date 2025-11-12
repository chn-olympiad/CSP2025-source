#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w,c,r;
	bool f=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	    scanf("%d",&a[i]);
	w=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
				if(a[i*n-j+1]==w)
				{
					f=1;
					c=i;
					r=j;
					break;
				}
		}
		else
		{
			for(int j=1;j<=n;j++)
				if(a[n*i-n+j]==w)
				{
				    f=1;
					c=i;
					r=j;
					break;
				}
		}
		if(f)break;
    }
    printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
