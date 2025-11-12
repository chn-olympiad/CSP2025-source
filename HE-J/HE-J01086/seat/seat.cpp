#include<bits/stdc++.h>
using namespace std;
int b[200],r=1,c=1,n,m,v;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&b[i]);
	v=b[1];
	int k=1,o=1;
	sort(b+1,b+1+n*m,cmp);
	 while(b[k]!=v)
	 {
	 	int p=0;
	 	if(r==n&&o)
	 	{
	 		c++;
			o=0;
			p=1;	
		}
		if(r==1&&(!o))
		{
			o=1;
			c++;
			p=1;
		}
		if(!p)
		{
			if(o) r++;
			else r--;
		}
		k++;
	 }
	 printf("%d %d",c,r);
	fclose(stdin);
	fclose(stdout);
}
