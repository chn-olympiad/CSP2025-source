#include <bits/stdc++.h>
using namespace std;



void mymain(){
	vector<int> a;
	int n, m;
	cin >> n >> m;
	int score, ming; //小R成绩、排名 
	for(int i = 0; i < n * m; i++){
		int b;
		cin >> b;
		if(i == 0) score = b;
		a.push_back(b);
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < a.size(); i++){
		 if(a[i] == score){
		 	ming = a.size() - i;
		 	break;
		 }
	}
	int x = 0, y = 1;  // x行，y列 
	bool flag = true; //true代表向下，false代表向上
	while(ming--){
		if(flag == true){
			if(x < n){  //正常走 
				x++;
//				cout << 1 << endl;
			}else{       //换一列 
				y++;
				flag = false;
//				cout << 2  << " " << flag << endl;
			}
		}else{
			if(x > 1){
				x--;
//				cout << 3 << endl;
			}else{
//				cout << 4 << endl;
				y++;
				flag = true;
			}
		}
//		cout << y << " " << x << endl;
	} 
	cout << y << " " << x << endl;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
//	int n;
//	cin >> n;
//	while(n--){
		mymain();
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 2
99 100 97 98
*/

//#Shang4Shan3Ruo6Shui4












