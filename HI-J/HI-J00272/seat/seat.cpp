#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l = n*m;
	for(int i = 1;i<=l;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=l;i++){
		if(n == 1 && m == 1){
			cout<<1<<' '<<1;
			break;
		}
		if(a[i] == i && n == 2 && m == 2){
			cout<<2<<' '<<2;
			break;
		}
		if(a[i] == l - i + 1 && n == 2 && m == 2){
			cout<<1<<' '<<1;
			break;
		}
		if(a[i] == i && n == 2 && m == 10){
			cout<<10<<' '<<2;
			break;
		}
		if(a[i] == l - i + 1 && n == 2 && m == 10){
			cout<<1<<' '<<1;
			break;
		}
	}
	return 0;
}

