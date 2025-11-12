#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int q,sum,n;
int ct[3]{};
int stu[N][3];
int l = 0;
void DFS(int f,int cnt){
	if(n == f){
		sum = max(sum,cnt);
		return;
	}
	for(int i = 0;i < 3;i++){
		ct[i]++;
		if(ct[i] > (n / 2)){
			ct[i]--;
			continue;
		}
		DFS(f + 1,cnt + stu[f][i]);
		ct[i]--;
	}
	
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> q;
	int t = q,b;
	while(q--){
		cin >> n;
		if(!b)b = n;
		for(int i = 0;i < n;i++){
			cin >> stu[i][0] >> stu[i][1] >> stu[i][2];
		}
		DFS(0,0);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < 3;j++){
				stu[i][j] = 0;
			}
		}
		cout << sum << '\n';
		sum = ct[1] = ct[2] = ct[3] = 0;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
