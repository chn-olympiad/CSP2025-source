#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin)
	//freopen("seat.out","w",stdout)
	int m,n,a[1000001],c,d;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){ 
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	if(a[1]=100){
		cout<<"1 1";
	}
	else if(m==1&&n==1){
		cout<<"1 1";
	}
	else if(n==1){
		for(int i=1;i<=m*n;i++){
			if(c==a[1]){
				d=i;
			}
		}
		cout<<m-d+1<<"1";
		return 0;
	}
	else if(m==1){
	   for(int i=1;i<=m*n;i++){
           if(c==a[1]){
           	d=i;
		   }
	   }
	   cout<<n-d+1<<"1";
	   return 0;
	}
	
	return 0;
}
