//GZ-s00045 第十二中学 刘可薇 
#include <bits/stdc++.h>
using namespace std;
int a[10005][3],b[10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t,n,s,k,l;
    int m=1,z,w;
	int x,y;
    cin>>t;
	while(m++){
		
	    s=0,k=0,l=0;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];	
		}
	}
		z=-100;
//		int u;
//		if(n<3){
//			u=1;
//		}else{
//			u=n/3;
//		}
//		for(int q=0;q<u;q++){
//			w=-100;
//			for(int j=0;j<3;j++){
//			    for(int i=0;i<n;i++){
//					if(b[i]=0){
//						if(q==0){
//							if(a[i][j]>=z){
//							z=a[i][j];
//							x=i;
//						}
//						}else{
//						    if(a[i][j]<=z&&a[i][j]>w){
//						    	w=a[i][j];
//						    	x=i;
//							}    	
//						}
//					}
//			    }
//				b[x]=1;
//			    if(q!=0){
//			    	z=w;
//				}
//			    if(j==0){
//			    	s+=z;
//				}else if(j==1){
//					k+=z;
//				}else{
//					l+=z;
//				}
//		    }
//		}
			for(int i=0;i<n;i++){
			z=-100;
			for(int j=0;j<3;j++){
				if(b[i]==0){
					if(a[i][j]>=z){
						z=a[i][j];
						y=j;
					}
				}
			}
		    if(y==0){
		    	s+=z;
			}else if(y==1){
				k+=z;
			}else{
				l+=z;
			}	
		}
		cout<<s+k+l<<endl;
		if(m>t){
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
}

