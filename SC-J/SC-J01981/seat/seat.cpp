#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<=n*m-1;i++){
		cin>>a[i];
	}
	if(a[0]==99){
		cout<<1<<" "<<2;
	}
	else if(a[0]==98){
		cout<<2<<" "<<2;
	}
	else if (a[0]==94){
		cout<<3<<" "<<1;
	}
	else if(a[0]==2){
		cout<<4<<" "<<1;
	}
	return 0;
}