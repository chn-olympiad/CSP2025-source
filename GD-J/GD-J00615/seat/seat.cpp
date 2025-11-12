#include <bits/stdc++.h>
using namespace std;
pair <int,int> k[200];

bool sb(pair <int,int> a,pair <int,int> b){
	return a.first > b.first;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	if(n == 1&&m ==1){
		cout << "1 1";
		return 0;
	}
	for (int i = 1;i <= n*m;i++){
		cin >> k[i].first;
		if(i == 1){
			k[i].second = 1;
		}
		else {
			k[i].second = 0;
		}
	}
	sort(k+1,k+n*m+1,sb);
	int s;
	for (int i = 1;i <= n*m;i++){
		if(k[i].second == 1){
			s = i;
		}
	}
	int c,r;
	for (int i = 1;i <= n;i++){
		if(i%2==1){
			for (int j = 1;j <= m;j++){
				s--;
				if(s == 0){
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else{
			for (int j = m;j >= 1;j--){
				s--;
				if(s == 0){
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
