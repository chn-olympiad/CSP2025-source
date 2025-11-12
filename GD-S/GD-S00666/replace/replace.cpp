#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,q,nxt[N][2][N];
string s[N][2];
string t[2]; 
vector<int> v[2];
bool fp[N],fs[N];
void calcnxt(int x,int y) {
	int sz=s[x][y].size(),j=-1; nxt[x][y][0]=-1;
	for(int i=1;i<sz;i++) {
		while(j>=0&&s[x][y][j+1]!=s[x][y][i]) j=nxt[x][y][j];
		if(s[x][y][j+1]==s[x][y][i]) j++;
		nxt[x][y][i]=j;
	}
}
void Find(int x,int y) {
	int j=-1;
	for(int i=0;i<t[y].size();i++) {
		while(j>=0&&s[x][y][j+1]!=t[y][i]) j=nxt[x][y][j];
		if(s[x][y][j+1]==t[y][i]) j++;
		if(j==s[x][y].size()-1) {
			v[y].push_back(i);
			j=nxt[x][y][j];
		}
	}
}
bool check(int l,int r) {
	for(int i=l;i<=r;i++) if(t[0][i]!=t[1][i]) return false;
	return true;
}
int work() {
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s[i][0]>>s[i][1];
		calcnxt(i,0); calcnxt(i,1);
	}
	while(q--) {
		cin>>t[0]>>t[1];
		fp[0]=fs[t[0].size()+1]=true;
		fp[1]=(t[0][0]==t[1][0]);
		for(int i=1;i<t[0].size();i++) fp[i+1]=(fp[i-1+1]&&(t[0][i]==t[1][i]));
		fs[t[0].size()]=(t[0][t[0].size()-1]==t[1][t[0].size()-1]);
		for(int i=t[0].size()-1;i>=0;i--) fs[i+1]=(fs[i+1+1]&&(t[0][i]==t[1][i]));
		int ans=0;
		for(int i=1;i<=n;i++) {
			v[0].clear(); v[1].clear();
			Find(i,0); Find(i,1);
			for(auto it:v[0]) {
				auto p=lower_bound(v[1].begin(),v[1].end(),it);
				if(p!=v[1].end()&&*p==it&&fp[it-s[i][0].size()+1]&&fs[it+1+1]) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) {
		work();
	}
	return 0;
}

