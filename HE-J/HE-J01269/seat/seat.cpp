#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int b=a[1],w,c,r; 
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		 if(a[i]==b)
		 {
		 	w=i;
		 	break; 
		 }
	}
	if(w%n==0)
	{
		c=w/n;
	}else{
		c=w/n+1;
	}
	if(c%2==0)
	{
		r=m-w%n+1; 
	}else{
		if(w%n==0)
		{
			r=m;
		}else{
			r=w%n;
		}
	}
	printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
