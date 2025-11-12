#include<bits/stdc++.h>
using namespace std;
const int N=300000;
struct node{
	int x,y,z;
}a[N];
int ans[N];
long long a1,b1,c1; 
long long t,n,cnt; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>t;
	for(int j=t;j>=1;j--){
	    cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}	
		long long m=n/2;	    
		for(int i=1;i<=n;i++){
			if(a[i].x==0&&a[i].y==0&&a[i].z==0){
				cnt+=0;
				break;
			}
		    if(a[i].x>max(a[i].y,a[i].z)&&a[i].y>0&&a[i].z>0){
			    a1++;
			    if(a1<=m){
				    cnt+=a[i].x;
			    }
		    }
		    if(a[i].y>max(a[i].z,a[i].x)&&a[i].x>0&&a[i].z>0){
			    b1++;
			    if(b1<=m){
				    cnt+=a[i].y;
			    }
		    }
		    if(a[i].z>max(a[i].x,a[i].y)&&a[i].y>0&&a[i].x>0){
			    c1++;
			    if(c1<=m){
				    cnt+=a[i].z;
			    }
		    }
			if(a[i].y==0&&a[i].z==0&&a[i].x>0){
			        a1++;												
					if(a1<=m&&(a[i].x+a[i+1].x)>(a[i+2].x+a[i+3].x)){    
						cnt+=max(a[i].x,a[i+1].x);	
						if((a1++)<=m){
							cnt+=min(a[i].x,a[i+1].x);
						}							
					}
					if(a1<=m&&(a[i].x+a[i+1].x)<(a[i+2].x+a[i+3].x)){    
						cnt+=max(a[i+2].x,a[i+3].x);	
						if((a1++)<=m){
							cnt+=min(a[i+2].x,a[i+3].x);
						}							
					}
					if(a1<=m&&(a[i].x+a[i+1].x)==(a[i+2].x+a[i+3].x)){    
						cnt+=max(a[i].x,a[i+1].x);	
						if((a1++)<=m){
							cnt+=min(a[i].x,a[i+1].x);
						}							
					}													
			}		    
			if(a[i].x==0&&a[i].z==0&&a[i].y>0){
			        b1++;
					if(b1<=m&&(a[i].y+a[i+1].y)>(a[i+2].y+a[i+3].y)){    
						cnt+=max(a[i].y,a[i+1].y);	
						if((b1++)<=m){
							cnt+=min(a[i].y,a[i+1].y);
						}							
					}	
					if(b1<=m&&(a[i].y+a[i+1].y)<(a[i+2].y+a[i+3].y)){    
						cnt+=max(a[i+2].y,a[i+3].y);	
						if((b1++)<=m){
							cnt+=min(a[i+2].y,a[i+3].y);
						}							
					}
						if(b1<=m&&(a[i].y+a[i+1].y)==(a[i+2].y+a[i+3].y)){    
						cnt+=max(a[i].y,a[i+1].y);	
						if((b1++)<=m){
							cnt+=min(a[i].y,a[i+1].y);
						}							
					}																		
			}
			if(a[i].x==0&&a[i].y==0&&a[i].z>0){
			        c1++;
					if(c1<=m&&(a[i].z+a[i+1].z)>(a[i+2].z+a[i+3].z)){    
						cnt+=max(a[i].z,a[i+1].z);	
						if((c1++)<=m){
							cnt+=min(a[i].z,a[i+1].z);
						}							
					}
					if(c1<=m&&(a[i].z+a[i+1].z)<(a[i+2].z+a[i+3].z)){    
						cnt+=max(a[i+2].z,a[i+3].z);	
						if((c1++)<=m){
							cnt+=min(a[i+2].z,a[i+3].z);
						}							
					}
					if(c1<=m&&(a[i].z+a[i+1].z)==(a[i+2].z+a[i+3].z)){    
						cnt+=max(a[i].z,a[i+1].z);	
						if((c1++)<=m){
							cnt+=min(a[i].z,a[i+1].z);
						}							
					}																				
			}
			if(a[i].x>0&&a[i].y>0&&a[i].z==0){
				if(a[i].x>=a[i].y){
					a1++;
					cnt+=a[i].x;
				}else{
					b1++;
					cnt+=a[i].y;
				}          					
		    }									
	    }
	    ans[j]=cnt;
		cnt=0,a1=0,b1=0,c1=0;
	}
    for(int k=t;k>=1;k--){
    	cout<<ans[k]<<endl;
	}
	return 0;
}
