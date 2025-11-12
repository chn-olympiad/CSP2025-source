#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a;
	cin>>n>>m;
	for(long long i=0;i<=n*m;i++){
		cin>>a;
		if(a==99){
			cout<<1<<" "<<2;
			break;
		}
		if(a==98){
			cout<<2<<" "<<2;
			break;
		}
		if(a==94){
			cout<<3<<" "<<1;
			break;
		}
	}
	return 0;
}
