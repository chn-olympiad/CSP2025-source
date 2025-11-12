#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int n;
		cin>>n;
		int x=0,y=0,z=0,x2=0,y2=0,z2=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(max(max(a,b),c)==a){
				if(x2<=n/2){
					x=x+a;
					x2++;	
				}
				else if(max(b,c)==b){
						if(y2<=n/2){
			 				y=y+b;
							y2++;
						}
						else{
							z=z+c;
							z2++;	
						}
				}
				else if(max(b,c)==c){
						if(z2<=n/2){
			 				z=z+c;
							z2++;
						}
						else{
							y=y+b;
							y2++;	
						}
				}
				
			}
			 if(max(max(a,b),c)==b){
			 	if(y2<=n/2){
					y=y+b;
					y2++;	
				}
				else if(max(a,c)==a){
						if(x2<=n/2){
			 				x=x+a;
							x2++;
						}
						else{
							z=z+c;
							z2++;	
						}
				}
				else if(max(a,c)==c){
						if(z2<=n/2){
			 				z=z+c;
							z2++;
						}
						else{
							x=x+a;
							x2++;	
						}
				}
			}
			 if(max(max(a,b),c)==c){
			 	if(z2<=n/2){
					z=z+c;
					z2++;	
				}
				else if(max(b,a)==b){
						if(y2<=n/2){
			 				y=y+b;
							y2++;
						}
						else{
							x=x+a;
							x2++;	
						}
				}
				else if(max(b,a)==a){
						if(x2<=n/2){
			 				x=x+a;
							x2++;
						}
						else{
							y=y+b;
							y2++;	
						}
				}
				
				
			}
		}
		cout<<x+y+z<<endl;
	}
	return 0;
} 

