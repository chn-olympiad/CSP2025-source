#include<iostream>
#include<map>
#include<cstring>
#include<vector>
#define ll long long
#define N 20005
using namespace std;
int n,q,cnt[N];
string s1[N],s2[N],t1,t2;
 
inline void solve() {
	ll ans=0;
	vector<int> a1[30],a2[30];
	for(int j=0;j<t1.length();j++) {
		a1[t1[j]-'a'].push_back(j);
	}
	for(int i=1;i<=n;i++) {
		int ls=s1[i].length();
		int lt=t1.length();
		if(ls>lt) continue;
		for(auto j:a1[s1[i][0]-'a']) {
			// j->ÆðÊ¼Î»ÖÃ
			if(j+ls>lt) continue;
			bool f1=1;
			for(int k=0;k<j;k++) {
				if(t1[k]!=t2[k]) {
					f1=0;
					break;
				}
			}
			if(!f1) break;
			f1=1;
			for(int k=j+ls;k<n;k++) {
				if(t1[k]!=t2[k]) {
					f1=0;
					break;
				}
			}
			if(!f1) continue;
			f1=1;
//			cout<<j;
			for(int k=j;k<ls;k++) {
//				cout<<k-lt+ls;
//				cout<<s1[i][k]<<" !";
				if(s1[i][k]!=t1[k+j]||s2[i][k]!=t2[k+j]) {
					f1=0;
					break;
				}
			}
			if(f1) ans++;
		}
//		cout<<endl;
	}
	cout<<ans<<endl;
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	if(n>=1000) {
		map<int,int> qq;
		for(int i=1;i<=n;i++) {
			int x1=-1,x2=-1;
			for(int j=0;j<s1[i].length();j++) {
				if(s1[i][j]=='b') x1=j;
				if(s2[i][j]=='b') x2=j;
				if(x1>=0&&x2>=0) break;
			}
			qq[x1-x2]++;
		}
		while(q--) {
			cin>>t1>>t2;
			ll ans=0;
			int x1=-1,x2=-1;
			for(int j=0;j<t1.length();j++) {
				if(t1[j]=='b') x1=j;
				if(t2[j]=='b') x2=j;
				if(x1>=0&&x2>=0) break;
			}
			cout<<qq[x1-x2]<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++) {
		cin>>s1[i]>>s2[i];
	}
	while(q--)  {
		cin>>t1>>t2;
		solve();
	}
	cout.flush();
	return 0;
}

//I love ccf pls give me 100 pts
