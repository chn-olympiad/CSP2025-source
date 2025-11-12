#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n,cnt=0;
	cin >> n;
	int a[500];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<=2) {
		cout << '0';
		return 0;
	}
	if(a[1]>a[2]+a[3]) cnt++;
	else if(a[2]>a[1]+a[3]) cnt++;
	else if(a[3]>a[1]+a[2]) cnt++;
	cout << cnt;
	return 0;
}
