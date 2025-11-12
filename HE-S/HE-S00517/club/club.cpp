#include<bits/stdc++.h>
using namespace std;
int t,n,h[50000],max1,sum1[6],sum2,sum3,o=0;
int m[500000][3]; 
int s[500000];
int bm[3];
int qwe;
int w;
int uio;
int main(){
	freopen("clue.in","r",stdin);
	freopen("clue.out","w",stdout);
	cin>>t;
	for(int l=0;l<t;l++){
		cin>>n;
		for(int k=o;k<o+n;k++){	
			for (int j=0;j<3;j++){	
			cin>> m[k][j];
			
		}
		h[k]=0;
		for(int i=0;i<=3;i++){
			
			if(h[k]<m[k][i]){
				
				
				s[k]=h[k];
				h[k]=m[k][i];
				qwe=h[0];
				if(bm[i]>n/2){
					for(int r=0;r<=n;r++){
						
						if(qwe>h[i]){
							qwe=h[i];
							uio=i;
						}
					}
					h[uio]=s[uio];
					
				}
			}
			
		}
		
		
		sum1[l]+=h[k];
		}
	
	
		o++;
	}
for(int i=0;i<t;i++){
	cout<<sum1[i]<<endl;
}

	
	
	return 0;
} 
