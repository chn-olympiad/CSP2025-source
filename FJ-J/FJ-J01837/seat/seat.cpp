#include<bits/stdc++.h>
using namespace std;
int n,m,r,w,x,y,t=1;;
int f[101],o[12][12];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int j=0;j<m;j++){
	  if(j%2==0){
	    for(int i=0;i<n;i++){
	  		o[i][j]=t;
	  		t++;
	  		}	
	  }
	  else{
	  	for(int i=n-1;i>=0;i--){
	  		o[i][j]=t;
	  		t++;
	  	}	
	  }
	}
	for(int i=0;i<n*m;i++){
		cin>>f[i];
	}
	r=f[0];
	sort(f,f+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(f[i]==r){
		  w=i+1;
		  break;	
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(o[i][j]==w){
				y=i+1;
				x=j+1;
			}
		}
	}
	cout<<x<<" "<<y<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
