#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}

int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int a[10005],b[10005][10005];
int m=0,n=0,k=0,move=0,shang=0,ys=0,jj=0;
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
}
k=a[1];
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=n*m;i++){
	if(a[i]==k){
		move=i;
	}
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		
		if(move<=n){
			cout<<j<<' '<<move;
			return 0;
		}
			if(move>n){
			shang=move/n;
		    ys=move%n;
		    jj=shang;
		    if((jj+1)%2==0){
		    	
		    	if(ys==0){
		    		cout<<shang<<' '<<n;
		    		return 0;
				}
		    	cout<<1+shang<<' '<<n-ys+1;
		    	return 0;
			}
			
			 if((jj+1)%2!=0){
			 	if(ys==0){
			 		cout<<shang<<' '<<1;
			 		return 0;
				 }
		    	cout<<1+shang<<' '<<ys;
		    	return 0;
			}
		   return 0;
		}
	}
}

	return 0;
}
