#include<bits/stdc++.h>
using namespace std;
int n, m, cnt = 0;
int s[101];
int mp[101][101]; 
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in","r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int p = n * m;
	for(int i = 1;i <= p;i++)
		cin >> s[i];
	int r = s[1];
	sort(s + 1, s + p + 1, cmp);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(i % 2 == 0){
				int t = m - j + 1;
				mp[i][t] = s[++cnt];
			}
			else
				mp[i][j] = s[++cnt];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(mp[i][j] == r){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
