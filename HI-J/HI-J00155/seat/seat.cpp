#include<bits/stdc++.h>
using namespace std;
int a[1000];
int cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; 
	int x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		x=a[1];
	}
	int y;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			y=i;
		}
	}
	int c=y/m+y%m; 
	cout<<c<<" "; 
	if(c%2==1){
		cout<<y/c;  
	}else if(c%2==0){
		cout<<y/c;
	}
	return 0;
}
