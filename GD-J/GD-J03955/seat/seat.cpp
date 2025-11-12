#include<bits/stdc++.h>
using namespace std;
long long n,m,ly[2020],lyq;
int main(){
	freopen("seat.in","r".stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> ly[i];
	}
	int qq=ly[1];
	sort(ly+1,ly+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(ly[i]==qq){
			lyq=n*m-i+1;
		}
	}
	int q=(lyq-1)/n+1;
	cout << q << ' ';
	if(q%2==0){
		cout << n-((lyq-1)%n+1)+1;
	}
	else if(q%2==1){
		cout << (lyq-1)%n+1;
	}
	return 0;
}
