#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[230],t;
int to_one(const int & a,const int & b){
	return a*m+b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>a[to_one(i,j)];
//			cout<<to_one(i,j)<<' ';
		}
//		putchar('\n');
	}
	t=a[0];
//	cout<<t<<'\n';
	sort(a,a+n*m,greater<int>());
	for(i=0;i<n*m;i++){
		if(a[i]==t){
			cout<<(i/m)+1<<' '<<((i/m)%2==0?i%m+1:m-i%m);
//			cout<<'\n'<<i;
			return 0;
		}
	}
	return 0;
}
/*
2 2
99 100 98 97

1 2

2 2
98 99 100 97

2 2

3 3
94 95 96 97 98 99 100 93 92

3 1
*/
