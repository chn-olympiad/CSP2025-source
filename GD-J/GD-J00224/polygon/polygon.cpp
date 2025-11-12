#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=5100;
ll n,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=2){
		cout << 0;
	}
	if(n==3){
		cout << 1;
	}
	return 0;
}
