#include<bits/stdc++.h>
using namespace std;
long long a[1000],t;
long long n,m;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(long long i=1;i<=n*m;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<'\n';
	for(long long i=1;i<=n*m;i++){
		if(t==a[i]){
			if(i%n==0){
				if(i/n%2==1){
					cout<<i/n<<' '<<n;
				}
				else{
					cout<<i/n<<' '<<1;
				}
			}else{
				if((i/n+1)%2==1){
					cout<<i/n+1<<' '<<i%n;
				}
				else{
					cout<<i/n+1<<' '<<n-i%n+1;
				}
			}
			return 0;
		}
	}
	return 0;
}
/*

4 4
5 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 

*/
