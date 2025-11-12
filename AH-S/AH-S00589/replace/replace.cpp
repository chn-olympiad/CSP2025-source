#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1, s2;
}a[200010];
int n, q, ans;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--){
		string t1, t2;
		cin>>t1>>t2;
		for(int i=1; i<=n; i++){
			int pos = t1.find(a[i].s1);
			if(pos == -1) continue;
			string tmp = t1;
			for(int j=pos; j<pos+a[i].s1.size(); j++){
				tmp[j] = a[i].s2[j-pos];
			}
			if(tmp == t2){
				ans++;
			}
		}
		cout<<ans<<endl;
		ans = 0;

	}
	return 0;
}