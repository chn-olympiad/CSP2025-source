#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,a[5000];
int he(int a[],int l){
	int sum=0;
	for(int i=0;i<l;i++){
		sum+=a[i];
	}
	return sum;
}
int max(int a[],int l){
	int ma=a[0];
	for(int i=1;i<l;i++){
		if(ma<a[i]){
			ma=a[i];
		}
	}
	return ma;
}
int duo(int i,int c,int b[]){
	if(c==i){
		return he(b,i)>max(b,i)*2?1:0; 
	}
	for(int j=c;j<n-i;j++){
		b[c+j]=a[j];
		return duo(i,c+1,b);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b[n],sum=0;
	for(int i=3;i<=n;i++){
	    sum+=duo(i,0,b);
	}
	cout<<sum;
	return 0;
}