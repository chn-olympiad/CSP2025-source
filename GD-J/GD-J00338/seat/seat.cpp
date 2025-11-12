//seat
#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n, m, rv, s;
struct p{
	int v, id;
}a[N*N];
int si[N][N];
bool cmp(p x, p y){
	return x.v>y.v;
}
int t, in;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m; s=n*m;
	for(int i=1; i<=s; i++){
		cin>>a[i].v;
		a[i].id=i;
	}
	rv=a[1].v;
	sort(a+1, a+1+s, cmp);
	for(int i=1; i<=m; i++){
		if(i%2){
			for(int j=1; j<=n; j++){
				si[i][j]=a[(i-1)*n+j].v;
				if(si[i][j]==rv){
					cout<<i<<" "<<j<<endl;
					return 0; 
				}
			}
		}else{
			for(int j=n; j>0; j--){
				si[i][j]=a[(i-1)*n+(n-j)+1].v;
				if(si[i][j]==rv){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			} 
		}
	}
	return 0;
}
/*
2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

*/
