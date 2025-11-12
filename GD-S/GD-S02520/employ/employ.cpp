#include<bits/stdc++.h>

using namespace std;

int n,m,c[505],b[505],book[505];
string s;

int dfs(int st){
	if(st > n){
		int x = 0,y = 0;
		for(int i = 1;i <= n;i++){
			if(s[i - 1] == '0')x++;
			else if(x >= c[b[i]] || y > c[b[i]])x++;
			else y++;
		}
		if(y >= m)return 1;
		else return 0;
	}else{
		int re = 0;
		for(int i = 1;i <= n;i++){
			if(!book[i]){
				b[st] = i;
				book[i] = 1;
				re += dfs(st + 1);
				book[i] = 0;
			}
		}
		return re;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++)cin >> c[i];
	if(n > 10){
		cout << 0 << endl;
		return 0;
	}
	cout << dfs(1) << endl;
	return 0;
}
