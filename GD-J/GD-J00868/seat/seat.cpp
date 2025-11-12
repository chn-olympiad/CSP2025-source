#include<bits/stdc++.h>
using namespace std;
int score[105],st[11][11];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,scoreR;
	cin >> n >> m;
	cin >> scoreR;
	for(int i = 2;i<=n*m;i++) cin >> score[i];
	score[1] = scoreR;
	sort(score+1,score+n*m+1,cmp);
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			int tmp = (i-1)*n + j;
			if(i % 2 == 1){
				st[i][j] = score[tmp];
			}else{
				st[i][abs(j-n) + 1] = score[tmp];
			}
		}
	}
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			if(st[i][j] == scoreR){
				cout << i << " " << j;
				return 0; 
			}
		}
	}
} 
