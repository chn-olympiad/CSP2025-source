#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int t,n,w[N][5];
int a[N],cnta,b[N],cntb,c[N],cntc,m[N],ans;
void init(){
	cnta = cntb = cntc = ans = 0;
	for(int i = 1;i < N;i++)
		a[i] = b[i] = c[i] = m[i] = 0;
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		init();
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> w[i][1] >> w[i][2] >> w[i][3];
			int maxn = max(w[i][1],max(w[i][2],w[i][3]));
			if(maxn == w[i][1])
				a[++cnta] = i;
			else if(maxn == w[i][2])
				b[++cntb] = i;
			else if(maxn == w[i][3])
				c[++cntc] = i; 
			ans += maxn;
		}
		int len = n / 2;
		if(cnta > len){
			int num = cnta - len;
			for(int i = 1;i <= cnta;i++){
				int now = a[i];
				int bpos = w[now][1] - w[now][2];
				int cpos = w[now][1] - w[now][3];
				m[i] = min(bpos,cpos);
			}
			sort(m + 1,m + 1 + cnta);
			for(int i = 1;i <= num;i++)
				ans -= m[i];
		}
		else if(cntb > len){
			int num = cntb - len;
			for(int i = 1;i <= cntb;i++){
				int now = b[i];
				int apos = w[now][2] - w[now][1];
				int cpos = w[now][2] - w[now][3];
				m[i] = min(apos,cpos);
			}
			sort(m + 1,m + 1 + cntb);
			for(int i = 1;i <= num;i++)
				ans -= m[i];
		}
		else if(cntc > len){
			int num = cntc - len;
			for(int i = 1;i <= cntc;i++){
				int now = c[i];
				int apos = w[now][3] - w[now][1];
				int bpos = w[now][3] - w[now][2];
				m[i] = min(apos,bpos);
			}
			sort(m + 1,m + 1 + cntc);
			for(int i = 1;i <= num;i++)
				ans -= m[i];
		}
		cout << ans << endl;
	}
	return 0;
}
