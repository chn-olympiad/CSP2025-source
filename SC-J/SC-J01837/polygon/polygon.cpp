#include<bits/stdc++.h>
using namespace std;

int n,a[5010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(n<=3){
		sort(a,a+n);
		if(a[0]+a[1]>a[2]) cout << 1;
		else cout << 0;
	}
	
	return 0;
}