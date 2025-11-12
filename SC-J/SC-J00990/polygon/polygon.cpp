#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans = 0;
	cin>>n;
	vector<int> A(n);
	for (int i = 0;i < n;i++){
		cin>>A[i];
	}
	for (int i = 0;i < n;i++){
		for (int j = i;j < n;j++){
			int sumx = 0,maxx = 0;
			for (int k = i;k < j + i;k++){
				sumx += A[k];
				maxx = max(maxx,A[k]);
			}
			if (sumx > 2 * maxx && j - i >= 2){
				ans++;
				ans = ans % 998244353;
			}
		}
	}
	cout<<(ans * 3) % 998244353;
	return 0;
}