#include <bits/stdc++.h>
using namespace std;
int n,m,t;
struct node{
	int id;
	int score;
};
node a[105];
bool cmp(node x,node y){
	return x.score > y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i].score;
		a[i].id = i;
	}
	sort(a + 1,a + n * m + 1,cmp);
	int x = 1,y = 1;
	for(int i = 1;i <= n * m;i++){
		if(a[i].id == 1){
			t = i;
			cout << x << " " << y << endl;
			break;
		}
		if(x % 2 == 1)y++;
		else y--;
		if(y == m + 1 || y == 0){
			x++;
			if(x % 2 == 1)y = 1;
			else y = m;
		}
	}
	
	return 0;
}

