#include <bits/stdc++.h>
using namespace std;
// Li Hao Ming JS-J00871 C402-034
int n,m,x,y,tmp,first;
int a[15][15];
int score[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int w = n * m;
	x = 1,y = 1;
	for(int i = 1;i <= w;i++){
		cin >> score[i];
	}
	int rs=score[1];
	sort(score+1,score+w+1,greater<int>());
	
	for(int i = 1;i <= w;i++){
		
		if(y % 2){
			if(x + 1 <= n){
				a[x][y] = score[i];
				x++;
			}else if(x == n){
				a[x][y] = score[i];
				if(y == m){
					break;
				}
				y++;
			}
		}else if(y % 2 == 0){
			if(x - 1 >= 1){
				a[x][y] = score[i];
				x--;
			}else if(x == 1){
				a[x][y] = score[i];
				if(y == m){
					break;
				}
				y++;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i][j] == rs){
				cout << j << " " << i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
