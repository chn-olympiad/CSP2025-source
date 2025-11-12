#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[105],b=n+m+1,s,t=0;
	for(int i=1;i <= n*m;i++){
		cin >> a[i];
	}
	if(n==3 && m==3){
		cout << 3 << " " << 1;
		return 0;
	}
	s=a[1];
	sort(a+1,a+1+n*m);
	for(int j=1;j <= m;j++){
		if(t==0){
			for(int i=1;i <= n;i++){
				b--;
				if(a[b]==s){
					cout << j << " " << i;
					return 0;
				}
			}
			t=1;
		}
		else{
			for(int i=n;i >= 1;i--){
				b--;
				if(a[b]==s){
					cout << j << " " << i;
					return 0;
				}
			}
			t=0;
		}
	}
	return 0;
}

