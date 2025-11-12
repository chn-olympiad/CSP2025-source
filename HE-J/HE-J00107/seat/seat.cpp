#include<bits/stdc++.h>
using namespace std;
int n,m,u=1,k=1,num;
int v[15][15],q[125],num1,mm;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
 	cin>>n>>m;
 	v[1][1]=1;
	    for(int i=1;i<=n*m;i++){
 			cin>>q[i];
 			if(q[i]>q[1]){
 				num++;
			 }
	    }
	num=num+1;
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=m;j++){
 			if(u%2!=0){
 				k++;
 			if(k>n){
 				k=n;
 				u++;
 			    v[k][u]=v[k][u-1]+1;
 			    if(v[k][u]==num){
 			    	cout<<u<<" "<<k;
 			    	mm++;
 			    	break;
				 }
 			    continue;
			}
			v[k][u]=v[k-1][u]+1;
			if(v[k][u]==num){
 			    	cout<<u<<" "<<k;
 			    	mm++;
 			    	break;
				 }
			}else{
				k--;
				if(k<1){
					k=1;
					u++;
					v[k][u]=v[k][u-1]+1;
					if(v[k][u]==num){
 			    	cout<<u<<" "<<k;
 			    	mm++;
 			    	break;
				 }
					continue;
				}
				v[k][u]=v[k+1][u]+1;
				if(v[k][u]==num){
 			    	cout<<u<<" "<<k;
 			    	mm++;
 			    	break;
				 }
			}
		 }
		 if(mm!=0){
		 	break;
		 }
	}
	//fclose(stdin);
	//fclose(stdout);
 	return 0;
 	
}
