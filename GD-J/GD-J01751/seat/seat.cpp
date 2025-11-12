#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int seats[105],m,n,fir,firi;
bool cmp(int x,int y){
	return (x>=y);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>seats[i];
	fir = seats[1];
	sort(seats+1,seats+n*m+1,cmp);
	for (int i=1;i<=n*m;i++) {
		if (seats[i]==fir){
			firi=i;
			break;
		}
	}
	if(firi%(2*n)<=n) cout<<firi/(2*n)*2+1<<' '<<firi%(2*n);
	else cout<<firi/(2*n)*2+2<<' '<<n-firi%n+1;
	return 0;
} 
