#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	int arr[5][100000][3];
	int N[t];
	for (int i = 0; i < t; i++){
		cin >> N[i];
		for (int j = 0; j < N[i]; j++){
			cin >> arr[i][j][0];
			cin >> arr[i][j][1];
			cin >> arr[i][j][2];
		}
	}
	for (int i = 0; i < t; i++){
		if (N[i] == 2){
			int manyidu[6], total_manyidu[t];
			for (int i = 0; i < t; i++){
				manyidu[0] = arr[i][0][0] + arr[i][1][1];
				manyidu[1] = arr[i][0][0] + arr[i][1][2];
				manyidu[2] = arr[i][0][1] + arr[i][1][0];
				manyidu[3] = arr[i][0][1] + arr[i][1][2];
				manyidu[4] = arr[i][0][2] + arr[i][1][0];
				manyidu[5] = arr[i][0][2] + arr[i][1][1];
				sort(manyidu, manyidu + 6, greater<int>());
				total_manyidu[i] = manyidu[0];
			}
			cout << total_manyidu[i] << '\n';
		}
		else{
			int max, max_manyidu[t];
			for (int i = 0; i < t; i++){
				max = 0;
				for (int j = 0; j < N[i]; j++){
					sort(arr[i][j], arr[i][j] + 3, greater<int>());
					max += arr[i][j][0];
				}
				max_manyidu[i] = max;
			}
			cout << max_manyidu[i] << '\n';
		}
	}
	return 0;
}
