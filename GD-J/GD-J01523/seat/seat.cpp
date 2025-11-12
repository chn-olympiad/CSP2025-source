#include<bits/stdc++.h> 
using namespace std;
int a[11][11];
struct s{
	int q,x=0;
};
s b[130];
int main(){
	long long int m,n,e=0,j=1,y,h;
freopen("seat.in","r",stdin);	
freopen("seat.out","w",stdout);
cin>>m>>n;
for(int i=1;i<=m;i++){
for(int j=1;j<=n;j++){
cin>>a[i][j];
b[i+j-1].q=a[i][j];	
}
} 
for(int i=m*n-1;i>=1;i--){
	for(int j=1;j<=i;j++){
		if(b[j].q<b[j+1].q)
		swap(b[j],b[j+1]);
	}
} 
	
for(int i=1;i<=m*n;i++){
if(a[1][1]==b[i].q){
	 b[i].x=i;
	 cout<<ceil((i/1.0)/m)<<" ";
	 if(i%2==0){
	 	if(i%m==0){
		  cout<<1;
	}
	 	else{
	 		cout<<m-i%m+1;
		 }
	 }
	 else{
	 	if(i%m==0){
		  cout<<m;
		  
	 }
	 else{
	 	cout<<i%m;
	 }
}
}
}


fclose(stdin);
fclose(stdout);
return 0;
}
