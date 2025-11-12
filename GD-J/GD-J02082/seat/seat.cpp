#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 15;
int b[N][N]; 

bool cmp(int x, int y){
	return x > y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;	cin>>n>>m;
	int x;
	vector<int> a;
	for(int i = 1;i <= n * m;i++){
		int y;	cin>>y;
		a.pb(y);
		if(i == 1)	x = y;
	}
	sort(a.begin(), a.end(), cmp);
	int k = 0;
	for(int j = 1;j <= m;j++){
		if(j % 2)
			for(int i = 1;i <= n;i++)	b[i][j] = a[k++];
		else
			for(int i = n;i >= 1;i--)	b[i][j] = a[k++];
	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(b[i][j] == x){
				cout<<j<<" "<<i<<'\n';
				return 0;
			}
		}
	}
	return 0;
}

