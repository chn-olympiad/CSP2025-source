#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+5;
ll t, n, v[N], b[10][N], c[10][N];
struct S{
	ll a, x, cnt, y;
}s[N][10];
int cmp(S s1, S s2){
	return s1.a>s2.a;
}
int main(){
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	cin >> t;
	while(t--){
		ll ans=0;
		for(int i=1;i<=3;i++){
			v[i]=0;
		}
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> s[i][j].a;
				s[i][j].x=j;
				s[i][j].y=i;
			}
			sort(s[i]+1, s[i]+4, cmp);
			v[s[i][1].x]++;
			b[s[i][1].x][v[s[i][1].x]]=s[i][1].a;
			c[s[i][1].x][v[s[i][1].x]]=s[i][1].y;
			if(v[s[i][1].x]>n/2){
				sort(b[s[i][1].x]+1, b[s[i][1].x]+v[s[i][1].x]+1, greater<int>());
				ll cnt1=c[s[i][1].x][v[s[i][1].x]];
				v[s[cnt1][2].x]++;
				b[s[cnt1][2].x][v[s[cnt1][2].x]]=s[cnt1][2].a;
				c[s[cnt1][2].x][v[s[cnt1][2].x]]=s[cnt1][2].y;
				if(v[s[cnt1][2].x]>n/2){
					sort(b[s[cnt1][2].x]+1, b[s[cnt1][2].x]+v[s[cnt1][2].x]+1, greater<int>());
					ll cnt2=c[s[cnt1][2].x][v[s[cnt1][2].x]];
					b[s[cnt2][3].x][v[s[cnt2][3].x]]=s[cnt2][3].a;
					c[s[cnt2][3].x][v[s[cnt2][3].x]]=s[cnt2][3].y;
					v[s[cnt1][2].x]--;
				}
				v[s[i][1].x]--;
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=v[i];j++){
				ans+=b[i][j];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
// Ren5Jie4Di4Ling5%

