// GZ-S00355 程袁浩 华师一 
#include <bits/stdc++.h>
#define int long long
#define upp(a,x,y) for(int a=x;a<=y;a++)
#define dww(a,x,y) for(int a=x;a>=y;a--)
#define pb push_back
#define PII pair<int,int>
using namespace std;
const int N=510;
int n,m;
int s[N],c[N],p[N];
bool st[N];
void solve() {
	cin>>n>>m;
	upp(i,1,n) {
		char cc;cin>>cc; 
		s[i]=cc-'0';
	}
	upp(i,1,n) cin>>c[i];
	upp(i,1,n) p[i]=i;
	int ans=0;
	do {
		int sum=0,cnt=0;
		upp(i,1,n) {
			if(s[i]==1&&cnt<c[p[i]]) sum++;
			else cnt++;
		}
		
		if(sum>=m) {
			ans++;
		}
	}while(next_permutation(p+1,p+1+n));
	cout<<ans<<endl;
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int tt;tt=1;
    while(tt--) solve();
    return 0;
}
/*
3 2
101
1 1 2

*/
