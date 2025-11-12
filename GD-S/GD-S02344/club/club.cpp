#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[10005][3]={},cmax[5]={},max=0,c[10005]={},cnt=0;
	cin >> t;
	for(int i=1;i<=t;i++){
	    cin >> n;
	    for(int i=1;i<=n;i++){
        	for(int j=1;j<=3;j++){
		        cin>>a[i][j];
		    }
	    }
        for(int i=1;i<=n;i++){
        	for(int j=1;j<=3;j++){
    	    	if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
				{
    	 	   		c[i]=a[i][1];
    		    	cnt+=1; 
    			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
				{
    	 	   		c[i]=a[i][2];
    		    	cnt+=1; 
    			}else
    			{
    	 	   		c[i]=a[i][3];
    		    	cnt+=1; 
    			}
				if(cnt > n/2){
					c[i]=0;
					cnt-=1;
				}
				max+=c[i];
    		}
    	}
    	cmax[i]=max;
    	cnt=0;
    	max=0;
	}
    for(int i=1;i<=t;i++){
    	cout<<cmax[i]<<endl;
    }
    return 0;
}
