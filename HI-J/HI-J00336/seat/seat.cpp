#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N];
int b[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int g=n*m;
	for(int i=1;i<=g;i++)
	{
		scanf("%d",&a[i]);
		if(i==1)
		{
			b[1]=a[i];
		}
	}
	sort(a+1,a+g+1);
	int shu=0; 
	for(int i=1;i<=g;i++)
	{
		if(a[i]==b[1])
		{
			shu=g-i;
			break;
		} 
	}
	int jie=0;
	int gg=1;
	for(int i=1;i<=m;i++)
	{
	    if(gg%2!=0)
	    {
	    	for(int j=1;j<=n;j++)
	    	{
	    		if(jie==shu)
	    		{
	    			int ii=i;
	    			int jj=j;
	    			printf("%d %d",ii,jj);
	    			return 0;
				}
				jie++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
	    	{
	    		if(jie==shu)
	    		{
	    			int ii=i;
	    			int jj=j;
	    			printf("%d %d",ii,jj);
	    			return 0;
				}
				jie++;
			}
		}
		gg++;
	}
	return 0;
}

