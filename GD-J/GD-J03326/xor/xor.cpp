#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int mark[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n , k;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		mark[a[i]++];
	}
	cout << mark[k];
	//不是你见过吗？这叫骗分，城里人？城里人你也骗不到分！ 
	return 0;
}
