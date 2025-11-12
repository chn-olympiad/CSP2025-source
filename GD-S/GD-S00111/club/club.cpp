#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		int sat=0,n;
		cin >> n;
		int arr[N][4];
		int peo[4];
		memset(arr,0,sizeof(arr));
		memset(peo,0,sizeof(peo));
		vector<int> go1,go2,go3;
		priority_queue<int> lm;
		for (int i = 1;i <= n;i++){
			cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
//			cout << "arr" << arr[i][1] << endl;
			if (arr[i][1] >= arr[i][2] && arr[i][1] >= arr[i][3]){
				peo[1]++; go1.push_back(i);
				sat+=arr[i][1];
//				cout << "sat" << sat << endl;
			}
			else if (arr[i][2] >= arr[i][3] && arr[i][2] >= arr[i][1]){
				peo[2]++; go2.push_back(i);
//				cout << "aaaaaaaa " << endl;
				sat+=arr[i][2];
//				cout << "sat" << sat << endl;
			}
			else{
				peo[3]++; go3.push_back(i);
				sat+=arr[i][3];
//				cout << "sat" << sat << endl;
			}
		}
		int move1 = (peo[1] > n/2) ? (peo[1] - n/2): 0;
		int move2 = (peo[2] > n/2) ? (peo[2] - n/2): 0;
		int move3 = (peo[3] > n/2) ? (peo[3] - n/2): 0;
		int move = move1+move2+move3;
//		cout << "move" << move1 << move2 << move3 << endl;
//		cout << "sat" << sat << endl;
		// in advance 
		if (move == 0){
			cout << sat << endl;
			continue;
		}
//		for (int i = 0;i < go1.size();i++){
//			cout << go1[i] << " " << endl;
//		}
		if (move1 > 0){
			for (int i = 0;i < go1.size();i++){
//				cout << "1:" << go1[i] << endl;
				if ((arr[go1[i]][2] - arr[go1[i]][1] > arr[go1[i]][3] - arr[go1[i]][1]) && move2 == 0) lm.push(arr[go1[i]][2]-arr[go1[i]][1]);
				else lm.push(arr[go1[i]][3]-arr[go1[i]][1]);
			}
		}
		if (move2 > 0){
			for (int i = 0;i < go2.size();i++){
//				cout <<  "2:" << go2[i] << endl;
				if ((arr[go2[i]][1] - arr[go2[i]][2] > arr[go2[i]][3] - arr[go2[i]][2]) && move1 == 0) lm.push(arr[go2[i]][1]-arr[go2[i]][2]);
				else lm.push(arr[go2[i]][3]-arr[go2[i]][2]);
			}
		}
		if (move3 > 0){
			for (int i = 0;i < go3.size();i++){
//				cout << "3:" <<  go3[i] << endl;
				if ((arr[go3[i]][1] - arr[go3[i]][3] > arr[go3[i]][2] - arr[go3[i]][3]) && move1 == 0){
					lm.push(arr[go3[i]][1]-arr[go3[i]][3]);
//					cout << go3[i] << ":" << arr[go3[i]][1]-arr[go3[i]][3] << endl;
				}
				else{
					lm.push(arr[go3[i]][2]-arr[go3[i]][3]);
//					cout << go3[i] << ":" << arr[go3[i]][2]-arr[go3[i]][3] << endl;
				}
				
//				
//				cout << "1" << arr[go3[i]][1]-arr[go3[i]][3] << endl;
//				cout << "2" << arr[go3[i]][2]-arr[go3[i]][3] << endl;
			}
		}
//		cout << "------" << endl;
		int s = lm.size();
		int ind = 1;
		while (move>0 && lm.size()){
			sat += (lm.top());
//			cout << ind << "choose" << lm.top() << endl;
			lm.pop(); 
			move--;
			ind++;
		}
		cout << sat << endl;
	}
	return 0;
} 

