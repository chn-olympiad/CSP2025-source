#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int score[101] = {};
	int c=1,r=1;//ÁÐ ÐÐ 
	for (int i = 0; i < n*m; i++){
		cin >> score[i];
	}
	bool down = true;
	int MyScore = score[0];
	for (int i = 1; i < n*m; i++){
		if (score[i] > MyScore){
			if (down == true){
				if (r < n){
					r++;
				}
				else {
					down = false;
					c++;
				}
			}
			else {
				if (r > 1){
					r--;
				}
				else{
					down = true;
					c++;
				}
			}
		}
	}
	cout << c << " " << r;
	fclose("seat.in");
	fclose("seat.out");
	return 0; 
} 
