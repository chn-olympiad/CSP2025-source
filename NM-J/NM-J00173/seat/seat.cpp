#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    int x,y,h,ans;
    
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>x>>y;
	int a[x*y];
    for(int i=0;i<x*y;i++){
    	cin>>a[i];
	}
	h=a[0];
    for(int i=x*y;i>=0;i--){
	    for(int j=0;j<i;j++){
	    	if (a[j]<a[j+1]){
	        int f=a[j+1];
	        a[j+1]=a[j];
	        a[j]=f;
	    	}
        }
    }
    for(int i=0;i<x*y;i++){
    	if(h==a[i]){
    		ans=i+1;
    		break;
		}
	}
	if(ans%x!=0){
		cout<<ans/x+1;
		if((ans/x+1)%2==0){
			if((y+1-ans%(y))!=0)cout<<(y-ans%(y));
			if((y+1-ans%(y))==0)cout<<y;
		}
		else {
			if(ans%(y)!=0)cout<<ans%(y);
			else cout<<y;
		}
	}
	else {
		cout<<ans/y;
		if(ans/x%2==0){
			if((y+1-ans%(y))!=0)cout<<(y-ans%(y));
			else cout<<y;
		}
		
		else {
			if((ans%(y))!=0)cout<<(ans%(y));
			else cout<<y;
		}
	}
	

    fclose("seat.in");
    fclose("seat.out");
    return 0;
}
