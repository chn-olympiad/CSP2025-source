#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define mod 1000000007
#define ari(x) array<int,(x)>
#define lcm(x,y) x/__gcd(x,y)*y
#define lowbit(x) ((x) & -(x))

const int N = 1005;
int a[N],a1,n,m; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++) cin>>a[i];
	a1 = a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int down = 1,x = 1,y = 1;
	for(int i = 1;i <= n*m;i++){
		if(a[i] == a1){
			cout<<x<<" "<<y;
			return 0;
		}
		if(down == 1){
			if(y == m){
				down = 0;
				x++;
			}else y++;
		}else{
			if(y == 1){
				down = 1;
				x++;
			}else y--;
		}
	}
	return 0;
}
