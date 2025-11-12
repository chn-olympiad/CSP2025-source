#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[110],mar;
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
	mar=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==mar){
			if((i%n==0?i/n:i/n+1)/n%2){
				cout<<(i%n==0?i/n:i/n+1)<<' '<<(i%n==0?n:i%n);
				return 0;
			}
			else{
				cout<<(i%n==0?i/n:i/n+1)<<' '<<n-(i%n==0?n:i%n);
				return 0;
			}
		}
	}
	return 0;
}//forty minutes 555
