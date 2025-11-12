#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
int n;
int w1=1,w2,w3;
cin>>n;
int s[n];
int k;
int l[1000][3]={0};
for(int i=0;i<n;i++){
	cin>>k;
	for(int j=0;j<k;j++){
		for(int h=0;h<3;h++){
			cin>>l[k][h];
		}
	}
  		for(int y=0;y<k;y++){
  			w1=w1*10;
		  }
		  w3=k;
		  int qwe=0,rty=0,w5,POI;
		  for(int p=w1/10;p<=w1;p++){
		  	qwe=0;
		  	w5=p;
		  	while(w3>=0){
		  		if(w5%10<=3){
		  			w5=w5/10;
		  			w3--;
		  	
		  			
				  }else{
				  	qwe=9;
				  	break;
				  }
			  }
			  if(qwe==9){
			  	break;
			  }
			  w5=p;
			  POI=0;
			  while(POI<k){
			  	rty=l[POI][w5%10];
			  w5=w5/10; 
				  POI++;	
			}
			  w2=max(w2,rty);
		
		
		  }
		  cout<<w2;

	}

	return 0;
} 
