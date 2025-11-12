#include<bits/stdc++.h>

using namespace std;

struct cai{
	int a,b,c,d;
}cs[300005];

int t,n,m,ans,x[100005],y[5];

bool cmp(cai xx,cai yy){
	return xx.d > yy.d;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--){
		m = ans = 0;
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
		cin >> n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> cs[++m].c;
				cs[m].a = i;
				cs[m].b = j;
			}
			cs[m - 2].d = cs[m - 2].c - cs[m - 1].c - cs[m].c;
			cs[m - 1].d = cs[m - 1].c - cs[m - 2].c - cs[m].c;
			cs[m].d = cs[m].c - cs[m - 1].c - cs[m - 2].c;
		}
		sort(cs + 1,cs + m + 1,cmp);
		for(int i = 1;i <= m;i++){
			if(!x[cs[i].a] && y[cs[i].b] < n / 2){
				x[cs[i].a] = 1;
				y[cs[i].b]++;
				ans += cs[i].c;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
