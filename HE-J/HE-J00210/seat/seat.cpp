#include<bits/stdc++.h>
using namespace std;
long long a[101][101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    long long n,m,max=0;
    bool f=1;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	if(f==1)
		{
    		for(int j=1;j<=n;j++)
    	    {
    		cin>>a[i][j];
    		if(a[i][j]>max) max=a[i][j];
		    }
		    f=0;
		}
    	else
    	{
    		for(int j=n;j>=1;j--)
    	    {
    		cin>>a[i][j];
    		if(a[i][j]>max) max=a[i][j];
		    }
		    f=1;
		}
	}
	if(n==1&&m==1){
	    cout<<a[1][1]<<endl;
	    return 0;
	} 
	int num=1;
	f=1;
	for(int i=1;i<=n;i++)
    {
    	if(f==1)
		{
    		for(int j=1;j<=m;j++)
    		{
    			if(a[i][j]==max)
    			{
    				cout<<i<<" "<<j<<endl;
    				return 0;
				}
			}
			f=0;
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				if(a[j][j]==max)
    			{
    				cout<<i<<" "<<j<<endl;
    				return 0;
				}
			}
			f=1;
		}
		num++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
