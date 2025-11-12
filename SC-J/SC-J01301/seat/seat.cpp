#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	int a[110];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int fs_xiao=a[1];
	int fs_seat_ming;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==fs_xiao)  fs_seat_ming=n*m-i+1;
	}
	int ls=fs_seat_ming/n;
	int rs=fs_seat_ming%n;
	if(ls%2!=0){ 
		if(rs==0){
			cout<<ls<<' '<<n;
		}
		else{
			cout<<ls+1<<' '<<n-rs+1;
		}
	} 
	if(ls%2==0){
		if(rs==0){
			cout<<ls<<' '<<1;
		}
		else{
			cout<<ls+1<<' '<<rs;
		}
	}
	return 0;
}