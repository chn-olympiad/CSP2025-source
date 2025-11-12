#include <bits/stdc++.h>
using namespace std;
//#define int long long
namespace qwq{
	const int N=6e6+114,K=27;
	int n,q;
	int rt,ch[N][K],fail[N],f[N],cnt[N];
	int Triel;
	int nTrie(){
		return ++Triel;
	}
	void ins(string s){
		int i=rt;
		for(char c:s){
			i=(ch[i][c-'a']?ch[i][c-'a']:ch[i][c-'a']=nTrie());
		}
		++cnt[i];
	}
	queue<int> Q;
	void build(){
		fail[rt]=rt;
		for(int i=0;i<K;++i){
			if(ch[rt][i]){
				Q.push(ch[rt][i]);
				fail[ch[rt][i]]=rt;
			}
			else ch[rt][i]=rt;
		}
		while(!Q.empty()){
			int u=Q.front();
			Q.pop();
			f[u]=f[fail[u]]+cnt[u];
			for(int i=0;i<K;++i){
				if(ch[u][i]){
					Q.push(ch[u][i]);
					fail[ch[u][i]]=ch[fail[u]][i];
				}
				else{
					ch[u][i]=ch[fail[u]][i];
				}
			}
		}
	}
	string mer(string& s1,string& s2){
		int l=0;
		while(s1[l]==s2[l]) ++l;
		int r=(int)s1.size()-1;
		while(s1[r]==s2[r]) --r;
		return string(s1.begin(),s1.begin()+l)+'{'+string(s1.begin()+l,s1.begin()+r+1)+string(s2.begin()+l,s2.begin()+r+1)+'{'+string(s1.begin()+r+1,s1.end());
	}
	signed mian(){
		rt=nTrie();
		cin >> n >> q;
		for(int i=1;i<=n;++i){
			string s1,s2;
			cin >> s1 >> s2;
			if(s1!=s2){
				ins(mer(s1,s2));
			}
		}
		build();
		while(q--){
			string s1,s2;
			cin >> s1 >> s2;
			string s=mer(s1,s2);
			int u=rt,ans=0;
			for(char c:s){
				u=ch[u][c-'a'];
				ans+=f[u];
			}
			cout << ans << "\n";
		}
		return 0;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	qwq::mian();
	return 0;
}
/*
	a-z 0-25
	{ 26
	
*/
