#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b;
    int arr[20][20],m,o=1,p=1,t=0;
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
       {
           cin>>arr[i][j];
        }
    }
    for(int i=1;i<=a;i++)
   {


       	for(int j=1;j<=b;j++)
    	  {
    		if(arr[o][p]<arr[i][j])
    		{
    		    m=arr[i][j];
    			arr[i][j]=arr[o][p];
    		    arr[1][1]=m;
    		o=i;
    		p=j;
    		i=o;
    		j=p;
    		t++;
			}
	    }


	}
	int y=t/b;
	int w=t%b;
	o=y+1;
	if(o%2==0) p=b-w;
	else p=w+1;
    cout<<o<<" "<<p;
    fclose(stdin);
	fclose(stdout);
    return 0;
}
