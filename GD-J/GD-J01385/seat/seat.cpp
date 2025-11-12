#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    int b[n][m];
    int a[105];
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+n*m+1);
	int c=n*m;
	int d=1;
	int f=m;
	while(f>0){
		for(int i=1;i<=n;i++)
    	{
	    	b[i][d]=a[c];
	    	c--;
	    }
	    d++;
	    f--;
	    if(f>0)
	    {
	    	for(int i=n;i>=1;i--)
	        {
	        	b[i][d]=a[c];
	        	c--;
	    	}
		}
	    else
	    {
	    	break;
		}
		d++;
		f--;
	}
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		if(b[i][j]==s)
    		{
    			cout<<j<<" "<<i<<endl;
			}
		}
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
} 
