#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k,a[1000],sum=0;
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		if(i%2==0){
			sum+=c;
		}
	}
	for(int i=1;i<=k;i++){
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
	}
	cout << sum;
	return 0;
}
