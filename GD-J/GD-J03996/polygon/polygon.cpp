#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen('polygon.in','r',stdin); 
	freopen('polygon.out','w',stdout);
	int n,a[5005],maxn=1,cnti=0,cntj=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=2;i<n;i++){
		cntj += maxn;
		maxn++;
	}
	cout << cntj % 998244353;
	return 0;
}
