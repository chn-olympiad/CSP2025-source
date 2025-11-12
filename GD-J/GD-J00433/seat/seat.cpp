#include<bits/stdc++.h>
using namespace std;
struct A{
	int C,N;
};
int n,m,I=0,X,Y;
bool cmp(A a,A b){
	if(a.C>b.C){
		if(a.N==I){
			I=b.N;
		}else if(b.N==I){
			I=a.N;
		}
		return true;
	}
	return false;
}
A a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].C;
		a[i].N=i;
	}
	sort(a,a+n*m,cmp);
	I++;
	X=((I+n-1)/n);
	cout<<X<<" ";
	if(X%2==1){
		if(I%n==0){
			cout<<n;
		}else{
			cout<<I%n;
		}
	}else{
		if(I%n==0){
			cout<<0;
		}else{
			cout<<n-I%n+1;
		}
	}
	return 0;
} 
