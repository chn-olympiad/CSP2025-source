#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a; i<=b; ++i)
#define F_(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define pii pair<int,int>
#define fr first
#define sc second
typedef long long ll;
const int N = 1e5+10;
int n,c[4][N],tot;
ll ar[N][4],ld[N],ans;
void init(){
	c[1][0] = c[2][0] = c[3][0] = 0;
	tot = 0; 
	ans = 0;
}
void work(){
	init();
	
	cin >> n;
	F(i,1,n) F(j,1,3) cin >> ar[i][j];
	
	F(i,1,n){
		int ma = max(max(ar[i][1],ar[i][2]),ar[i][3]);
		if (ma == ar[i][1]) c[1][++c[1][0]] = i;
		else if (ma == ar[i][2]) c[2][++c[2][0]] = i;
		else c[3][++c[3][0]] = i;
		
		ans += ma;
	}
	
	int op = 0;
	if (c[1][0] > n/2) op = 1;
	else if (c[2][0] > n/2) op = 2;
	else if (c[3][0] > n/2) op = 3;
	
	if (op){
		F(i,1,c[op][0]){
			int p = c[op][i];
			int res = -1;
			if (op==1) res = max(ar[p][2],ar[p][3])-ar[p][1];
			if (op==2) res = max(ar[p][1],ar[p][3])-ar[p][2];
			if (op==3) res = max(ar[p][1],ar[p][2])-ar[p][3];
			
			ld[++tot] = res;
		}
		sort(ld+1,ld+tot+1,greater<ll>());
		F(i,1,c[op][0]-n/2) ans += ld[i];
	}
	
	cout << ans << "\n";	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int _; cin>>_;
	while (_--) work();
	return 0;
} 
