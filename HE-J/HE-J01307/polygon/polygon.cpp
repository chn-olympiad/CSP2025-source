#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,m=0;
	cin >> n;
	if(n<3){
		cout << 0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
		m=max(m,a[i]);
		sum+=a[i];
	}
	if(sum>m*2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
