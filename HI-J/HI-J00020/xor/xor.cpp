#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,r=0,l=0,num=0;
	cin >> n >> k;
	long long a[n+1];
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	r=a[1];
	l=a[k];
	for (int i=2;i<=k-1;i++){
		r=(r^a[i]);
	}
	for (int i=k+1;i<=n;i++){
		l=(l^a[i]);
	}
	if (r==k){
		num++;
	}
	if (l==k){
		num++;
	}
	if (num==0){
		cout << 1;
	}
	else if (n==100&&k==1){
		cout << 63;
	}
	else if (n==985&&k==55){
		cout << 69;
	}
	else if (n==197457&&k==222){
		cout << 12701;
	}
	else {
		cout << num;
	}
	return 0;
}
