#include<bits/stdc++.h>
using namespace std;
int n,m,h,l,temp,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[(n*m+1)];
	cin>>a[1];
	y=a[1];
	for(int i = 2;i<=(n*m);i++){
		cin>>a[i];
	}
	sort(a+1,a+(n*m+1),cmp);
	for(int i =1;i<=(n*m);i++){
		if(a[i]==y){
			temp=i;
			break;
		}
	}
	if(temp%n!=0){
		l=(temp/n)+1;
	}
	else{
		l=temp/n;
	}
	if(l%2==0){
		h=n-(temp%n)+1;
	}
	else{
		h=(temp%n);
	}
	cout<<l<<" "<<h;
	return 0;
} 
