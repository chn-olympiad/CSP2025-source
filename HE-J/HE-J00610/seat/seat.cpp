#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r"stdin),;
	freopen("number.out","w",stdout);
int n,m,r=1,c=1,a[100005];
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
	if(c%2==1){
		
		 if(a[1]<a[i]){
		 		 
    r+=1;
	}
	if(r>n){
	int r=n;
	c++;
		 
	}
}
	if(c%2==0){
		
		 if(a[1]<a[i]){
		 	
			 
    r-=1;}
	if(r<1){
	int r=1;
	c++;
		 
	}
}

}
if(r<1){
	r+=1;
}
if(r>n){
	c++;
	r-=n;
}
	cout<<c<<" "<<r<<endl;
	return 0;
}
