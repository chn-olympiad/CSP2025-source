#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int c=0;
	int o;
	int w;
	int t;
	int n;
	int count1=1;
	int count2=1;
	int count3=1;
	int a1[100];
	int a2[100];
	int a3[100];
	int daan[100];
	int x=0;
	int y=0;
	int z=0;
	int j=1;
	cin>>t;
	int a[200][3];
	for(int h=0;h<t;h++){
		cin>>n;
		w=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			j=1;
			if(a[i][j]>a[i][j+1]&&a[i][j]>a[i][j+2]){
				if(count1>w){
					if(a[i][j+1]>a[i][j+2]){
						a2[count2]=a[i][j+1]; 
						count2++;
					}else{
						a3[count3]=a[i][j+2];
						count3++;
					}
				}else{
					a1[count1]=a[i][j];
				    count1++;
				}			
				
			}else if(a[i][j+1]>a[i][j]&&a[i][j+1]>a[i][j+2]){
				if(count2>w){
					if(a[i][j+2]>a[i][j]){
						a3[count3]=a[i][j+2]; 
						count3++;
					}else{
						a1[count1]=a[i][j];
						count1++;
					}
				}else{
					a2[count2]=a[i][j+1];
				    count2++;
				}	
		    }else if(a[i][j+2]>a[i][j]&&a[i][j+2]>a[i][j+1]){
		    	if(count3>w){
					if(a[i][j]>a[i][j+1]){
						a1[count1]=a[i][j];
						count1++; 
					}else{
						a2[count2]=a[i][j+1];
						count2++;
					}
			    }else{
			    	a3[count3]=a[i][j+2];
				    count3++;
				}
				
			}else if(a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2]){
				if(count1>count2&&count3>count2){
					a2[count2]=a[i][j+1];
					count2++;	
				}else if(count2>count1&&count3>count1){
					a1[count1]=a[i][j];
					count1++;
				}else if(count1>count3&&count2>count3){
					a3[count3]=a[i][j+2];
					count3++;
				}
			}else if(a[i][j]==a[i][j+1]){
				if(count1>count2){
					a2[count2]=a[i][j+1];
					count2++;
				}else if(count2>count1){
					a1[count1]=a[i][j];
					count1++;
				}
			}else if(a[i][j+1]==a[i][j+2]){
				if(count2>count3){
					a3[count3]=a[i][j+2];
					count3++;
				}else if(count3>count2){
					a2[count2]=a[i][j+1];
					count2++;
				}
			}else if(a[i][j]==a[i][j+2]){
				if(count1>count3){
					a3[count3]=a[i][j+2];
					count3++;
				}else if(count3>count1){
					a1[count1]=a[i][j];
					count1++;
				}
			}
		}
	    for(int i=1;i<=count1;i++){
	    	x=x+a1[i];
		}
		for(int i=1;i<=count2;i++){
	    	y=y+a2[i];
		}
		for(int i=1;i<=count3;i++){
	    	z=z+a3[i];
		}
		count1=1;
	    count2=1;
	    count3=1;
		o=x+y+z;	
		daan[c]=o;
		x=0;
		y=0;
		z=0;
		o=0;
		c++;				
	}
	for(int i=0;i<t;i++){
		cout<<daan[i]<<endl;
	}
	return 0;
}

