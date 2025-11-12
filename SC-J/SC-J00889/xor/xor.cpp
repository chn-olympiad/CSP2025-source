#include<iostream>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int m,n,p,z;
    cin>>m>>n;
    p=0;
    z=0;
    int a[m+1];
    int b[2][100];
    for(int i=1;i<m+1;i++){
    	cin>>a[i];
	}
	for(int i=1;i<m+1;i++){
		int k=a[i];
		if(k==n){
			b[0][p]=i;
			b[1][p]=i;
			p++;
			z++;
		}
		else {			
			for(int j=i+1;j<m+1;j++){
				k=(k^a[j]);
				if(k==n){
					b[0][p]=i;
					b[1][p]=j;
					p++;
					z++;								
				}
 			}
		}	
	}
	for(int i=0;i<p;i++){ 
		for(int j=i+1;j<p;j++){
			if(b[1][i]>=b[0][j]&&b[0][i]<=b[1][i]){
				z--;
			}
		}
	}
	cout<<z;
    return 0;
}