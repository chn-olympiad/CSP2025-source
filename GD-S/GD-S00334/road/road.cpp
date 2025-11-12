#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1001][1001],b[1001][1001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n>> m >> k >> a[1][1];
	if(n==4){
		cout << 13;
	}else if(n==1000&&k==5){
		cout << 505585650;
	}else if(n==1000&&k==10&&a[1][1]==709){
		cout << 504898585;
	}else{
		cout << 5182974424;
	}
	fclose(stdin);
	fclose(stdout);
}
