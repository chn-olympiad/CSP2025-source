#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+15;
typedef long long ll;
struct node{
	int v,id;
}a[N];

int b[15][15];
int n,m,s;

bool cmp(node u,node w){
	return u.v > w.v;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	s = n * m;
	for(int i = 1;i <= s;i++){
		cin >> a[i].v;
		a[i].id = i;
	}
		
	sort(a + 1,a + 1 + s,cmp);
	
	int x = 1,y = 1,k = 1;
	
	for(k = 1;k <= s;k++){
		b[x][y] = a[k].id;
		if(y % 2 == 1){
			if(x == n) y++;
			else x++;
		}
		else{
			if(x == 1) y++;
			else x--;
		}
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(b[i][j] == 1){
				cout << j << ' ' << i << '\n';
				return 0;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

