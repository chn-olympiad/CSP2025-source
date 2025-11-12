#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,a[1010],sum,x,k=1,e=1,f=1,z=0;
cin>>n>>m;
x=n*m;
for(int i=1;i<=x;i++){
	cin>>a[i];
	if(i==1)sum=a[i];
}
sort(a+1,a+x+1);
for(int i=x;i>=1;i--){
	if(k==m+1){
		if(z==0){
			e+=1;f=n;k=1;z=1;
		}
		else{
			e+=1;f=1;k=1;z=0;
		}
	}
	if(a[i]==sum){
		cout<<e<<" "<<f;
		return 0;
	}
	if(z==0){
		f++;k++;
	}
	if(z==1){
		f--;k++;
	}
}
return 0;
}
