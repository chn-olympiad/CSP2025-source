#include <bits/stdc++.h>
using namespace std;
long long a1[15][15];
struct mon{
	long long id,cj;	
} a[105];
bool cmp(mon x,mon y){
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;cin >> n >> m;
	for(long long i = 1 ; i <= n*m; i++){
		cin >> a[i].cj;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1 ; i <= n*m ; i++){
		if(a[i].id==1){
			if((i/m+1)%2!=0&&i%m!=0){
				cout << (i/m+1) << " " << n-(i/m+1)*n+i;
			}
			else if((i/m)%2!=0&&i%m==0){
				cout << (i/m) << " " << n-(i/m)*n+i;
			}
			else if((i/m+1)%2==0){
				cout << (i/m+1) << " " << (i/m+1)*n-i+1;
			}
			else{
				cout << (i/m) << " " << (i/m)*n-i+1;
			}
		}
	}
	
	return 0;
} 