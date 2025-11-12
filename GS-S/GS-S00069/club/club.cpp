#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    int n,maxn=0;
    cin>>n;
    int a1=0,b1=0,c1=0;
    for(int i=0;i<n;i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    		if(a>b&&a>c&&a1<n/2){
				a1++;
				maxn+=a;
				continue; 

			}

//	
	    	else if(b>c&&b>a&&b1<n/2){
				b1++;
				maxn+=b;
				continue; 	

			}

		    else if(c>a&&c>b&&c1<n/2){
				c1++;
				maxn+=c;
				continue; 	

			}
			else if(c>a||c>b&&c1<n/2){
				c1++;
				maxn+=c;
				continue; 
				
			}
	    	else if(b>c||b>a&&b1<n/2){
				b1++;
				maxn+=b;
				continue; 	


			}
			else if(a>b||a>c&&a1<n/2){
				a1++;
				maxn+=a;
				continue; 
			}
}

	cout<<maxn;
}
    return 0;
}
