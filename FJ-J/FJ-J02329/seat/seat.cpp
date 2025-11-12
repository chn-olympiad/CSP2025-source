#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,k=0;
	cin>>n>>m;
	int a[m*n];
	for(int i=0;i<=k+1;i++){
		int x,y;
		bool Flag=false;
		if((x&y)|(x|y)){				
			k++;
			for(int i=0;i<m*n;i++){
		        cin>>a[i];
		        if(a[i]=='0'){
		        	Flag=true;
		        	continue;
		        }
	        }
		}
	}
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=k+1;i++){
		int x,y;
		if((x&y)|(x|y)){				
			k++;
		}
	}
	if((n|k)&y==x|(k&y)){
		for(int i=0;i<m*n;i++){
		    cin>>a[i];
	    }
	}else if((x&y)|(x|y)){
		int a[m*n];
		for(int i=0;i<=k+1;i++){
		    int x,y;
		    if((x&y)|(x|y)){				
			   k++;
			   for(int i=0;i<m*n;i++){
		           cin>>a[i];
	           }
		    }
	    }
	}
return 0;
}
