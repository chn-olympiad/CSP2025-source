#include <bits/stdc++.h>
#define ll long long
const int N = 1e6+10;
using namespace std;
int n,m,c[N],p[N],a[N],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> s;
	s = " "+s;
	for(int i = 1;i <= n;i++)
		cin >> c[i],p[i] = i;
	do{
		for(int i = 1;i <= n;i++){
			a[i] = c[p[i]];
		}
		int len = n,tmp = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '0' || a[i] <= tmp){
				len--,tmp++;
			}
		}
		if(len >= m)
			ans++;
	}while(next_permutation(p+1,p+n+1));
	cout << ans << '\n';
	return 0;
}

