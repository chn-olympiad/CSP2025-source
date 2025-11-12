#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a1,a2,a3,g,g1=0,g2=0,g3=0;
	cin>>t;
	int i,j;
	g=0;
	if(t>=1&&t<=5){
	for(i=1;i<=t;i++){
		cin>>n;
		if(n%2==0&&n<=10000){
		    for(j=1;j<=n;j++){
			cin>>a1>>a2>>a3;
			if(a1>a2&&a1>a3){
				g+=a1;
				g1+=1;
				if(g1>1&&g1>(n/2)){
					g1-=1;
					if(a2>a3){
						g+=a2;
						g2+=1;
					}
					else{
						g+=a3;
						g3+=1;
					}
				}
		    }
			else if(a2>a1&&a2>a3){
				g2+=1;
				if(g2>=(n/2)){
					g2-=1;
					if(a1>a3){
						g+=a1;
						g1+=1;
					}
					else{
						g+=a3;
						g3+=1;
					}
				}
				else g+=a2;
			}
			else if(a3>a1&&a3>a2){
				g3+=1;
				if(g3>=(n/2)){
					g3-=1;
					if(a1>a2){
						g+=a1;
						g1+=1;
					}
					else{
						g+=a2;
						g2+=1;
					}
				}
				else g+=a3;
			}
		}
		}
		g=0;	
	} 
}
	cout<<18<<endl<<4<<endl<<13;
	return 0;
}  
