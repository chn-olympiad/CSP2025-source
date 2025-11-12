#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,zd=-1,x,k,o=0;
cin>>n>>m;
int a[n*m+1];
int b[n*m+1];
	
for(int i=1;i<=m*n;i++){
		cin>>a[i];
		k=a[1];
}
for(int i=1;i<=m*n;i++){
zd=-1;
for(int j=1;j<=m*n;j++){
			if(zd<a[j]){
			zd=a[j];
			x=j;
		}
		}
	b[i]=zd;	
a[x]=-1;

}



for(int i=1;i<=m;i++){
		if(i%2!=0){
		for(int j=1;j<=n;j++){
			o++;
			if(b[o]==k){
				cout<<i<<" "<<j;
				return 0;
			}
			
		}
			
			}else{
				for(int j=n;j>=1;j--){
					o++;
			if(b[o]==k){
				cout<<i<<" "<<j;
				return 0;
			}
			
		}
			}
}
return 0;
}
