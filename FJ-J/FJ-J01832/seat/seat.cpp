#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
			if(a[i][j]>=a[1][1]){
				ans++;
			}
		}
	}
	int l = ans/n;
	int h = ans%n;
	if(h!=0){
		l++;
	}
	if(l%2==0){
		h = n-h+1;
	}
	else{
		if(h==0){
			h = n;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
