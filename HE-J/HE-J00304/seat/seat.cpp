#include<bits/stdc++.h>
using namespace std;

const int N = 110;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
PII a[N * N]; // first表示成绩 second表示编号 
int dx[2] = {1, -1};

int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin>>n>>m;
	for(int i = 1 ; i <= n * m ; i ++){
		int p;
		cin>>p;
		a[i] = {p, i};
	}
	
	sort(a + 1, a + n * m + 1);
	reverse(a + 1, a + n * m + 1);
	
	int x = 1, y = 0, pos = 0, dis = 1;
	for(int j = 1 ; j <= m ; j ++){
		
		
		dis ^= 1;
		y ++;
		pos ++;
		if(a[pos].second == 1){
			cout<<y<<' '<<x;
			return 0;
		}
		
		do{
			x += dx[dis];
			pos ++;
			if(a[pos].second == 1){
				cout<<y<<' '<<x;
				return 0;
			}
		}while(x != 1 && x != n);
	}
	
	return 0;
}
