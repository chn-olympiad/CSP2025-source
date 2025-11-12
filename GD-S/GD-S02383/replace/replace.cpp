#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,e,f,ans;
struct ff{
	int l,r,l1,r1;
}g[1000005];
string c,d;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> a >> b;
	for(int i = 1; i <= a; i++){
		cin >> c >> d;
		for(int j = 0; j < c.size(); j++){
			if(c[j] == 'b'){
				e = j;
			}
		}
		for(int j = 0; j < d.size(); j++){
			if(d[j] == 'b'){
				f = j;
			}
		}
		g[i].l = e;
		g[i].r = c.size() - e - 1;
		g[i].l1 = f;
		g[i].r1 = d.size() - f - 1;
	}
	for(int i = 1; i <= b; i++){
		cin >> c >> d;
		for(int j = 0; j < c.size(); j++){
			if(c[j] == 'b'){
				e = j;
			}
		}
		for(int j = 0; j < d.size(); j++){
			if(d[j] == 'b'){
				f = j;
			}
		}
		ans = 0;
		for(int j = 1; j <= a; j++){
			if(e >= g[j].l && c.size() - e - 1 >= g[j].r && e - g[j].l + g[j].l1 == f && c.size() - e - 1 - g[j].r + g[j].r1 == d.size() - f - 1){
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
