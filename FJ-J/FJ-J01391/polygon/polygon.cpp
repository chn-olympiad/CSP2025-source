#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[50001];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(2*max(a[1],max(a[2],a[3])) < a[1]+a[2]+a[3])
	cout << 1;
	else
	cout << 0;
}
