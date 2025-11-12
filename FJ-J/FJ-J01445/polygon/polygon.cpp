#include<bits/stdc++.h>
using namespace std;

const int MAXN=5009;
int a[MAXN];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	int fangan=0;
	if (n<3){
		cout << fangan;
		return 0;
	}
	int he=a[1]+a[2]+a[3],
	for (int i=1;i<=n;i++){
		if (he)
	}
	cout << a[1];
	return 0;
}
