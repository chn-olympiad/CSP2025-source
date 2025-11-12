#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[n*m];
    int sum=0;
    for(int i=0; i<n*m; i++)
    {
        cin>>a[i];
        sum=a[1];
    }
    if(n==1 and m==1){
    	c=1;
    	r=1;
	}
	else{
		for(int i=0; i<n*m; i++)
    	{
    	    sort(a,a+n*m);
    	    for(int j=n; j>=0; j--)
    	    {
    	        for(int k=m; k>=0; k--)
    	        {
    	            if(a[i]==sum)
    	            {
   	                 c=j;
   	                 r=k;
    	            }
    	        }
    	    }
    	}
	}
    
    cout<<c<<' '<<r;
}

