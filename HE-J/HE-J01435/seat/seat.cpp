#include <bits/stdc++.h>

using namespace std;


int main(){
	int n,m,pai;
    cin>>n>>m;
    int b[100];
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int c=b[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<n*m;j++){
        	if(b[i]>b[j]){
			pai=b[i];
			b[i]=b[j];
			b[j]=pai;
			}
		}
    }
    for(int i=1;i<=n*m;i++){
        cout<<b[i];
    }for(int i=1;i<=n*m;i++){
       if(b[i]=c){
       	    if((i/m+1)%2==0){
       	   		cout<<i%m<<" "<<i/m+1;
				break;  
		    }else{
		    	cout<<m-i%m+1<<" "<<i/m+1;
		    	break;
			}
	   }
    }
    
    return 0;
}

