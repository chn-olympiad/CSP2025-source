#include <bits/stdc++.h>
using namespace std;
map <string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,cnt;
	cin >> n >> q;
	string s1,s2;
	while(n--){
		cin >> s1 >> s2;
		mp[s1] = s2;
	}
	string t1,t2;
	while(q--){
		cnt = 0;
		cin >> t1 >> t2;
		if(mp[t1] == t2) cnt++;
		int x = t1.size(),y = t2.size();
		string q = "",w = "";
		for(int i = 0;i < min(x,y);i++){
			if(t1[i] != t2[i]){
				for(int j = i;j < min(x,y);j++){
					q += t1[i];
					w += t2[i];
				}
				break;
			}
		}
		if(mp[q] == w) cnt++;
		x = q.size(),y = w.size();
		string e = "",r = "";
		if(x != y){
			e = q;
			r = w;
			if(mp[q] == w) cnt--;
		}
		else{
			for(int i = x - 1;i >= 0;i--){
				if(t1[i] != t2[i]){
					for(int j = i;j < x;j++){
						e += q[i];
						r += w[i];
					}
					break;
				}
			}
		}
		if(mp[e] == r) cnt++;
		cout << cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
