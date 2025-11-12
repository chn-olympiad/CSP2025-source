#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 250;
int a[N];
int n,m;
int pos;
bool cmp(int x,int y){return x > y;}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int x = 1,y = 1;
	for(int i = 1;i <= n * m;i ++)cin >> a[i];
	pos = a[1];
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;i ++){
		if(a[i] == pos){
			cout << y << " " << x;
			return 0;
		}
		if(y % 2 == 0){
			x --;
			if(x == 0){
				x = 1;
				y ++;
			}
		}else if(y % 2 == 1){
			x ++;
			if(x == n + 1){
				x = n;
				y ++;
			}	
		}
	}
	return 0;
}


