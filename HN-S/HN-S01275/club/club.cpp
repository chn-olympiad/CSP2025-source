#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=1,n=2,a[200][200],s=0,s1=0,s2=0,w[10000],w1[10000],w2[10000],max1=0,max2=0,max3=0,y[10000];
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			for(int z=1;z<=3;z++){
				scanf("%d",&a[j][z]);
				if(max1<a[j][z]){
					max1=a[j][z];
					w[j]=max1;
					y[j]=z;
				}
			}
			if(y[j]==1){
				w1[j]=max(a[j][2],a[j][3]);
			}else if(y[j]==2){
				w1[j]=max(a[j][1],a[j][3]);
			}else if(y[j]==3){
				w1[j]=max(a[j][1],a[j][2]);
			}
			max1=0;
		}	
		if(n==2){	
			if(y[1]==y[2]){
				if(w[1]>w[2]){
					cout<<w1[2]+w[1]; 
				}else if(w[1]==w[2]){
					if(w1[1]>w1[2]){
						cout<<w[2]+w1[1];
					}else{
						cout<<w[2]+w1[2];
					}					
				}else{
					cout<<w1[1]+w[2]; 
				}
			}else cout<<w[1]+w[2];
		}
	}
	return 0;
}
