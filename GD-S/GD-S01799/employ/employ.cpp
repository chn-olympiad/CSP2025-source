#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&-x)
#define pii pair<int,int>
#define N 1000010
const ll mod = 998244353;
int n,m,a[N],ans;bool c[N];
int p[N];// ееап 
int main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){char tmp;cin >> tmp;c[i] = (tmp=='1');}
	for(int i = 1;i <= n;++i)cin >> a[i],p[i] = i;sort(a+1,a+n+1);
	do{
		int bef = 0;
		for(int i = 1;i <= n;++i){int x = p[i];if(!c[i] || bef >= a[x])++bef;}
		if(n - bef >= m)++ans;
	}while(next_permutation(p+1,p+n+1));
	cout << ans;
	return 0;
} 
