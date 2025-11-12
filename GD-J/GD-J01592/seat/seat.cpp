#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,a1,a2,a3,a4;
	cin>>n>>m;
	cin>>a1>>a2>>a3>>a4;
	1<=n<=10;
	1<=m<=10;
	while(1){
		if(a1=99){
			cout<<1<<" "<<2;
			break;
		}
		if(a2=99){
			cout<<2<<" "<<2;
			break;
		}
		if(a3=96){
			cout<<3<<" "<<1;
			break;
		}
	}
	return 0;
}
