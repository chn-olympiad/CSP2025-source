#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,k;
int a[105];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n*m;i++){
        cin>>a[i];
}
k=a[0];
sort(a,a+n*m);
int i;
for(i=n*m;i>0;i--){
        if(k==a[i]){
                break;
        }
}
int s=0;
c=1;
r=1;
while(s!=i){
	if(s%2==1){
		for(int r=n;r>=1;r--){
			s++;
		}
	}
	else{
		for(int r=1;r<=n;r++){
			s++;
		}
	}
	c++;
	s++;	
}
cout<<c<<" "<<r;
}
