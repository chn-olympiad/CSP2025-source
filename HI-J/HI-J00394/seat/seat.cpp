#include<bits/stdc++.h>
using namespace std;
int n,m,k,k2,_x,_y;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	k=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==k)k2=i+1;
	}
	if(k2%n==0){
		_x=k2/n;
		if(_x%2==0){
			_y=1;
		}else{
			_y=n;
		}
	}else{
		_x=k2/n+1;
		if(_x%2==0){
			_y=n-(k2%n)+1;
		}else{
			_y=(k2%n);
		}
	}
	cout<<_x<<" "<<_y;
	return 0;
} 
//2 2 99 100 97 98
//3 3 94 95 96 97 98 99 100 93 92
