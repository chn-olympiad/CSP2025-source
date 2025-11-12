#include<bits/stdc++.h>
using namespace std;
const int N = 15;
const int M = N*N;
int n,m,a[N][N],x,y,tot,rank,b[M],mark;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) {
		cin >> b[i];
	}
	mark = b[1];
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==mark){
			rank =i;
			continue;
		}
	}
	x = rank/n+1;
	y = rank%(n*2);
	if(!(x&1)){
		y = 2*n-y+1;
	}
	cout << x << " " << y;
}