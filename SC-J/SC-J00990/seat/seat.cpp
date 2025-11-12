#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> A(n * m,0);
	for (int i = 0;i < n * m;i++){
		cin>>A[i];
	}
	int b = A[0],k = n * m - 1;
	vector<vector<int> > S(n,vector<int> (m));
	sort(A.begin(),A.end());
	for (int i = 0;i < m;i++){
		if (i % 2 == 0){
			for (int j = 0;j < n;j++){
				S[j][i] = A[k];
				k--;
			}
		}else if (i % 2 == 1){
			for (int j = n - 1;j >= 0;j--){
				S[j][i] = A[k];
				k--;
			}
		}
	}
	for (int i = 0;i < n;i++){
		for (int j = 0;j < m;j++){
			if (S[i][j] == b){
				cout<<j + 1<<' '<<i + 1;
				return 0;
			}
		}
	}
}