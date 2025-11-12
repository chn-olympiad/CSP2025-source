#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,b,c,d=0,f=0,e=0,k=0,h;
	cin>>a;
	for(int i=0;i<a;i++){	
		cin>>b;
		
		for(int s=0;s<b;s++){
			for(int j=0;j<3;j++){
				cin>>c;
				if(c>d){
					d=c;
					e++;
					
				}				
			}
			if(h==e){
				k++;
				}else{h=e;}
			f+=d;	
		}
		if((k+1)>(b/2)){cout<<(b/2)*d;}
		if((k+1)<=(b/2)){cout<<f;}
			
			
	}
	
	return 0;
	}
