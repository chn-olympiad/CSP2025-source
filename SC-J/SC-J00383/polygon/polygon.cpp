#include<bits/stdc++.h>
using namespace std;
int n,a[5010],f[5010],m,sum;
int c(int x,int y){
	int ret=1;
	for(int i=1;i<=x;i++){
		ret*=y-i+1;
	}
	for(int i=1;i<=x;i++){
		ret/=i;
	}
	return ret;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=3;i<=n;i++){
		sum+=c(i,n);
	}
	cout << sum;
	return 0;
}