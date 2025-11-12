#include<bits/stdc++.h>
using namespace std;
int c,r,x,n,m,b[105],d,Rl,Rh,e,z=100,nm,z1;
int sc(int z){
	for(int i=z;i>=1;i--){
		if(b[z]!=0){
			int o=i;
			
			return o;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>e;
		if(i==1){
			x=e;
		}
		b[e]++;
	}
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				z1=sc(z);
				if(z1==x){
					cout<<i<<" "<<j;
					return 0;
				} 
				z=sc(z)-1;
			}
		}else{
			for(int j=1;j<=n;j++){
				z1=sc(z);
				if(z1==x){
					cout<<i<<" "<<j;
					return 0;
				} 
				z=sc(z)-1;
			}
		}
	}
		
	return 0;
}
