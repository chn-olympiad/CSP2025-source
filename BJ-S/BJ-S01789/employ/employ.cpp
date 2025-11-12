#include <bits/stdc++.h>

using namespace std;

const int mod = 998244253;
const int Nmax = 5e2 + 7;

int n, m;
int s[Nmax];
int c[Nmax];
bool book[Nmax];
int ans;

void DFS(int day, int employ, int unemploy){
	if(day > n){
		if(employ >= m)
			ans++;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!book[i]){
			book[i] = true;
			if(unemploy >= c[i])
				DFS(day + 1, employ, unemploy + 1);
			else if(s[day] == 0)
				DFS(day + 1, employ, unemploy + 1);
			else if(s[day] == 1)
				DFS(day + 1, employ + 1, unemploy);
			book[i] = false;
		}
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		char ch;
		cin >> ch;
		s[i] = (ch - '0');
	}
	for(int i = 1;i <= n;i++)
		cin >> c[i];
	DFS(1, 0, 0);
	cout << ans << endl;
	return 0;
}