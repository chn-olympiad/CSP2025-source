#include<bits/stdc++.h>
using namespace std;

int n,m,a[105];
int score,in;

struct node{
	int x;
	int y;
};

node dfs(node s,int cnt){
	if(cnt == in) return s;
	cnt++;
	if(s.y % 2 == 1 && s.x != n){
		s.x++;
		dfs(s,cnt);
	}
	else if(s.y % 2 == 0 && s.x != 1){
		s.x--;
		dfs(s,cnt);
	}
	else if(s.x == n || s.x == 1){
		s.y++;
		dfs(s,cnt);
	}
	else return {0,0};
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		if(i==1) score = a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i] == score){
			in = n*m-i+1;
		}
	}
	node ans = dfs({1,1},1);
	cout << ans.y << " " << ans.x << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
