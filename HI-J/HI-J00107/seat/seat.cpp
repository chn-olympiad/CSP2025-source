#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==m){
		cout<<n<<' '<<m;
		return 0;
	}
	else{
		cout<<n<<' '<<n-1;
		return 0;
	}
	return 0;
}
