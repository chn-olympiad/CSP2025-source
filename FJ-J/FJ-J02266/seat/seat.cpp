/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

5 3
7 1 2 3 4 5 6 8 9 10 11 12 13 14 15
*/

#include <bits/stdc++.h>
using namespace std; 

int n,m,a[110]; 

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
	int k1=a[1],k2;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k1){
			k2=i;
		}
	}
	if(k2<=n){
		cout<<1<<" "<<k2;
	}else{
		int c=k2/n+1;
		cout<<c<<" ";
		if(c%2==1){
			cout<<k2%n;
		}else{
			cout<<n+1-(k2%n);
		}
	}
	return 0;
}
