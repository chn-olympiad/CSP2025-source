#include<bits/stdc++.h>
using namespace std;
int n,m;
int l[400]={};
int r,f;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m*n;i++){
		cin>>l[i];
	}
	r=l[0];
	sort(l,l+n*m,cmp);
	for(int i=0;i<m*n;i++){
		if(l[i]==r){
			f=i+1;
			break;
		}
	}
	if(f%n==0)cout<<f/n;
	else cout<<f/n+1;
	if((f%n)%2==1){
		if(f%(n+1)==n){
			cout<<" "<<1;
			return 0;
		}
		cout<<" "<<n-f%(n+1);//ио 
	}else{
		cout<<" "<<f%(n+1);//об 
	}
	return 0;
} 

