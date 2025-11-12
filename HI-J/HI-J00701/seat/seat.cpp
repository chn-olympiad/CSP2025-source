#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin); 
freopen("seat.out","w",stdout);
int n,m,k[1000],lll;
cin>>n>>m;
lll=1;
for(int i=1;i<=n*m;i++){
cin>>k[i];	
}
int l,ll;
for(int i=1;i<=n*m-1;i++){
	for(int f=1;f<=n*m-1;f++){
		if(k[f]<k[f+1]){
			k[f]+=k[f+1];
			k[f+1]=k[f]-k[f+1];
			k[f]=k[f]-k[f+1];
			if(lll==f){
			lll+=1;
			}else if(lll==f+1){
			lll-=1;
		}
		}   
	} 
}
int c,cc;
c=lll/n+1;
cc=lll%n;
if(lll%n==0){
	c-=1;
	cc=n;
}
if(c%2==0)cc=n-cc+1;
cout<<c<<" "<<cc;
return 0;
}
