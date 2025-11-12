#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
long long n,m,a[N],r;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	long long i,j=1;
	for(i=1;a[i-1]!=r;i++){
		if(i%(2*n)<n+1&&i%(2*n)>1){
			j++;
		}else if(i%(2*n)>n+1||i%(2*n)==0){
			j--;
		}
	}
	cout << (i-2)/n+1 << ' ' << j;
}
