#include <bits/stdc++.h>
#define rep(i,x,y) for(int i = x; i <= y; i++)
using namespace std;

const int MAXN  =505;
int n, m,s[MAXN], c[MAXN];
int it[MAXN];
signed  main(){
	
	cin.tie(0), ios::sync_with_stdio(0);
	cin >> n >> m;
	char ch;
	rep(i, 1, n) cin >> ch, s[i] = ch- '0';
	rep(i, 1, n) cin >> c[i];
	int res=0;
	do{
        int cnt=0;
        int ans =0;
        rep(i, 1, n){
            if(cnt >= c[i] || s[i] == 0){
                cnt++;
            }else{
                ans++;
            }
        }
        if(ans >= m) res++;
	}while(next_permutation(it + 1, it + 1 + n));
	cout << res;
	return 0;
}
