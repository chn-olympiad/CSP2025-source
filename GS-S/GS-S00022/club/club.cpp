#include <bits/stdc++.h>
 using namespace std;
 int a[200010][3],z[200010];
 int main(){
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	int t,n,max=0,b1h=0,b2h=0,b3h=0,bb,b1=0,b2=0,b3=0,h=1;
 	cin>>t;
 	for(int j=0;j<t;j++){
 		cin>>n; 
 		for(int i=0;i<n;i++){
 			for(int ou=1;ou!=4;ou++){
 				cin>>a[i][ou]; 
			 }
		}
		for(int ij=1;ij!=4;ij++){
			for(int i=1;i<n;i++){
 				if(max<a[i][ij]){
 					max=a[i][ij];
 					bb=ij;
 					h=0;
			 	}
 				if(max==a[i][ij]) h++;
			}
 			if(ij==1){
 				b1+=max*h;
 				b1h+=1+h;
			 }
 			if(ij==2){
 				b2+=max*h;
 				b2h+=h;
			 }
 			if(ij==3){
 				b3+=max*h;
 				b3h+=h;
			 }
 			max=0;
	 	}
	 	z[j]=b1+b2+b3;
	 	max=0;
	 	b1h=0;
	 	b2h=0;
	 	b3h=0;
	 	b1=0;
	 	b2=0;
	 	b3=0;
	 	h=0;
	}
	for(int i=0;i<t;i++){
		cout<<z[i]<<endl;
	}
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
}
