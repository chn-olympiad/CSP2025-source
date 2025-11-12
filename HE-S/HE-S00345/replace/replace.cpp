#include <bits/stdc++.h>
using namespace std;
struct ss{
	string s1, s2;
}s[200005];
struct tt{
	string s1, s2;
}t[200005];
string xixi (string s, int l, int r){
	s.erase(l, r-l);
	return s;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, ans=0;
	cin>>n>>q;
	for(int i = 0;i<n;i++) cin>>s[i].s1>>s[i].s2;
	for(int i = 0;i<q;i++){
		cin>>t[i].s1>>t[i].s2;
		for(int j = 0;j<n;j++){
			int t1ll = 0;
			int t1lr = t[i].s1.find(s[j].s1);
			int t2ll = 0;
			int t2lr = t[i].s2.find(s[j].s2);
			if(t1lr!=-1 && t2lr!=-1) {
				int t1rl   = t1lr+s[j].s1.length();
				int t1rr   = t[i].s1.length();
				string t1l = xixi(t[i].s1, t1lr, t1rr);
				string t1r = xixi(t[i].s1, t1ll, t1rl);
				int t2rl   = t2lr+s[j].s2.length();
				int t2rr   = t[i].s2.length();
				string t2l = xixi(t[i].s2, t2lr, t2rr);
				string t2r = xixi(t[i].s2, t2ll, t2rl);
				if 	   (t[i].s1==t[i].s2)	  ans++;
				else if(t1l==t2l && t1r==t2r) ans++;
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
