#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n = 0,m = 0;
	cin >> n >> m;
	int seat_[1000];
	int seat_t[1000];
	for(int i = 0;i < n*m;i++){
		int temp = 0;
		cin >> temp;
		seat_[i] = int(temp);
	}
	int score_r = seat_[0];
	for (int j = 0;j < n*m ;++j){
		int max_ = -1;
		int i = 0,g = 0;
		for (;i<n*m;i++){
			if(seat_[i] > max_){
				max_ = seat_[i];
				g = i;
			}
		}
		seat_[g] = 0;
		seat_t[j] = max_;
	}
	int dw;
	for(int j = 0;j < n*m;++j){
		if (seat_t[j] == score_r){
			dw = j;
		}
	}
	dw++;
	int r = 0,c = 0;
	c = dw/m;
	if(dw%n>0) c += 1;
	if(c%2 == 1) r = dw-(c-1)*n;
	if(c%2 == 0) r = n+1-(dw-(c-1)*n);
	cout << c << ' '<< r;
}
