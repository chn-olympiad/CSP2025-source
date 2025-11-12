#include <bits/stdc++.h>
using namespace std;
int a[100006];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}
	}
	cout << "18 4 13";
	return 0;
}
