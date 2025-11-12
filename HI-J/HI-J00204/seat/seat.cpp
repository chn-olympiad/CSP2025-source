#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int score[n * m + 1];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> score[j];
		}
	}
	int s = score[0],o;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;){
			if(score[j] < score[j + 1]) swap(score[j],score[j + 1]);
		}
	}
	for(int i = 0;i < n * m;i++){
		if(score[i] == s) o = i + 1;
	} 
	cout << o / n << " " << o % n;
	return 0;
}
