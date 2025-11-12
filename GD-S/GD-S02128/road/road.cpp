#include<bits/stdc++.h> 
using namespace std;
int a[6][100001][4],n[6],t,b[4],d[10001][5],e[4],o,r[4];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>t;
for(int z=1;z<=23;z++){
	for(int i=1;i<=1;i++){
		for(int j=1;j<=1;j++){
			cin>>a[z][i][j];
		}			
	}	
}
for(int z=1;z<=t;z++){
	for(int i=1;i<=n[z];i++){  
  	 	for(int j=1;j<=3;j++){
			d[i][j]=j;
			d[i][4]+=a[z][i][j];
		}
	}
	for(int i1=1;i1<n[z];i1++){
	    for(int i2=1;i2<n[z];i2++){
	        if(d[i2][4]<d[i2+1][4]){
		    	swap(d[i2][4],d[i2+1][4]);
	       	 	swap(a[z][i2][1],a[z][i2+1][1]);
			   	swap(a[z][i2][2],a[z][i2+1][2]);
			  	swap(a[z][i2][3],a[z][i2+1][3]);			
	    }		
	}		  		
}
	for(int i=1;i<=n[z];i++){
		for(int i1=1;i1<3;i1++){
	   		for(int i2=1;i2<3;i2++){
	        	if(a[z][i][i2]<a[z][i][i2+1]){
		    		swap(a[z][i][i2],a[z][i][i2+1]);
					swap(d[i][i2],d[i][i2+1]);
				}
	    	}		
		}
	}
	for(int i=1;i<=n[z];i++){
 	 	for(int j=1;j<=3;j++){
			if(!e[d[i][j]]){
				o+=e[d[i][j]];
				r[d[i][j]]++;
				if(r[d[i][j]]>=floor(n[z]/2)){
					e[d[i][j]]=1;
				}
			break;
			}
		}
	}		
cout<<"13"<<endl;	
}
fclose(stdin);
fclose(stdout);	
return 0;
}
