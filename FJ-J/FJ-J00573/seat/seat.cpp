#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],sum=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		if (i!=1&&a[i]>a[1]){
			sum++;
		}
	}
	int y=ceil(sum*1.0/n);
	if (y%2==1){
		cout << y << ' ';
		if (sum%n==0){
			cout << n;
		}else{
			cout << sum%n;
		}
	}else{
		cout << y << ' ';
		if (sum%n==0){
			cout << 1;
		}else{
			cout << n+1-sum%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
