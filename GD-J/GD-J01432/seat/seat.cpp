#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[110]; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l;
	for(int i=1;i<=n*m;i++){
		if(a[i]==s)l=i;
	}
	int g=l;
//	cout<<l<<endl;
	if(l%n==0){
		l=l/n;
	}
	else l=(l/n)+1;
	cout<<l<<" ";
    int h;
    if(l%2==0){
    	h=g-(l-1)*n;
    	h=n-h+1;
	}
	else h=g-(l-1)*n;
	cout<<h; 
	return 0;
}
/*
6 2
11 6 7 3 9 5 2 1 10 12 4 8
*/
