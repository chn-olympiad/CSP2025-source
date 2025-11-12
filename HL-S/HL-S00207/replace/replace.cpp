#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5;
int n,q,sum;
pair<string, string > s[maxn];
bool vis[maxn];
string before,goal;
void func(string now,bool ok){
	if(now == goal && !ok){
		sum++;
		return;
	}
	for (int i = 1; i <= n; i++){
		if(vis[i]) continue;
		int ii = now.find(s[i].first);
		string aa = now;
		if(ii != -1){
			for (int j = 0; j < s[i].second.size(); j++){
				now[j+ii] = s[i].second[j];
			}
			vis[i] = 1;
			func(now,0);
			vis[i] = 0;
		} 
		now = aa;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> s[i].first >> s[i].second;
	}
	while(q--){
		cin >> before >> goal;
		memset(vis,0,sizeof(vis));
		sum = 0;
		func(before,1);
		cout << sum << endl;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}