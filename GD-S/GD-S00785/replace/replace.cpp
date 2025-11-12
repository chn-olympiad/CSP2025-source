#include<bits/stdc++.h>
using namespace std;
struct ss{
	int a, b;
}s[200005][2];
string ta1, ta2;
int n, q, ans;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		string u, v;
		cin >> u >> v;
		int ok = 0;
		for(int j = 1;j <= u.size();j++){
			if(ok == 0 && u[j] == 'a')
				s[i][0].a ++;
			if(ok == 1 && u[j] == 'a')
				s[i][0].b ++;
			if(u[j] == 'b')
				ok = 1;
		}
		int ok = 0;
		for(int j = 1;j <= v.size();j++){
			if(ok == 0 && v[j] == 'a')
				s[i][1].a ++;
			if(ok == 1 && v[j] == 'a')
				s[i][1].b ++;
			if(v[j] == 'b')
				ok = 1;
		}
	}
	while(q--){
		cin >> ta1 >> ta2;
		ans = 0;
		int a[2][2];
		int ok = 0;
		for(int j = 1;j <= ta1.size();j++){
			if(ok == 0 && ta1[j] == 'a')
				a[0][0]++;
			if(ok == 1 && ta1[j] == 'a')
				a[0][1] ++;
			if(ta1[j] == 'b')
				ok = 1;
		}
		for(int j = 1;j <= ta2.size();j++){
			if(ok == 0 && ta2[j] == 'a')
				a[1][0]++;
			if(ok == 1 && ta2[j] == 'a')
				a[1][1] ++;
			if(ta2[j] == 'b')
				ok = 1;
		}
		for(int i = 1;i <= n;i++){
			if((((s[i][0].a <= a[0][0]) && (s[i][0].b <= a[0][1])) && ((s[i][1].a <= a[1][0]) && (s[i][1].b <= a[1][1]))))
				ans++;
		}
	}
	cout << ans;
	return 0;
}
