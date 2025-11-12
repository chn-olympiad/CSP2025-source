#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<=n;i++){
		cin >> a[i];
	}
	int b[n];
	for(int i=0;i<=n;i++){
		cin >> a[i];
	}
	 int sum=min(n,m);
	 cout << sum;
	 return 0;
} 
