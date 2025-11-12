#include <bits/stdc++.h>
using namespace std;
int s[205],n,m,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> r;
	s[1]=r;
	for(int i=2;i<=n*m;i++){
		cin >> s[i];
	}
	sort(s+1,s+n*m+1);
	int sum=n*m;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(s[sum]==r){
					cout << i << " " << j;
					return 0;
				}
				sum--;
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(s[sum]==r){
					cout << i << " " << j;
					return 0;
				}
				sum--;
			}
		}
	}
	return 0;
}
