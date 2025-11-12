#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin>>n>>m;
	int a;
	cin>>a;
	int rank = 1;
	for(int i = 1; i < n*m; i++){
		int b;
		cin>>b;
		if (b > a){
			rank++;
		}
	}
	int row = (rank - 1) / n;
	int row_pos = (rank-1) % n;
	if (row%2 == 1){
		row_pos = n-1-row_pos;
	}
	cout<<row + 1<<' '<< row_pos + 1;
	return 0;
}