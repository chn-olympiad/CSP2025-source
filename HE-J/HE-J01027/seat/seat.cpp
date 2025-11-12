#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
long long n,m;
int num[MAXN];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>num[i];
	}
	long long s=num[1];
	sort(num+1,num+n*m+1);
	for(long long i=n*m;i>=1;i--){
		long long j = n*m-i+1;
		long long xx=0,yy=0;//xx¡–  yy≈≈ 
		if (j <= n){
			xx = 1;
		}else{
			if (j % n == 0){
				xx = j/n;
			}else{
				xx = j/n+1;
			}
		}
		if (j <= n){
			yy = j;
		}else if(j % n == 0 || j % n == 1){
			if (j % (2*n) == 0 || j % (2*n) == 1){
				yy = 1;
			}else{
				yy = n;
			}
		}else{
			if ((j / n) % 2 == 1){
				yy = n-j%n+1;
			}else{
				yy = j%n;
			}
		}
		if (num[i] == s){
			cout<<xx<<" "<<yy;
		}
	}
	return 0;
}
