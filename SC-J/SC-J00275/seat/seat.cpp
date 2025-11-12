#include<bits/stdc++.h>
using namespace std;
int a[105];
int r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+m*n);
	int cnt_r;
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			cnt_r=n*m-i+1;
			break;
		}
	}
	int c=1,r=1;
	int fl=0;
	if(cnt_r%n==0){
		c=cnt_r/n;
	}
	else{
		c=cnt_r/n+1;
	}
	if(c%2==1){
		r=cnt_r-(c-1)*n;
	}
	else{
		r=n-(cnt_r-(c-1)*n)+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/