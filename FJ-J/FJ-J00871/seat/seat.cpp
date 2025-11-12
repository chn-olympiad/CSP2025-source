#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105]={0};
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int x=a[0];
	sort(a,a+n*m,cmp);
	//cout<<a[0];
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			cout<<(i/n)+1<<" "; 
			if(i/n%2==0)  cout<<(i%n)+1;
			else  cout<<n-(i%n);
			break;
		}
	}
}





//	for(int i=0;i<n*m;i++){
//		cin>>a[i];
//	}
//	cout<<a[0];
