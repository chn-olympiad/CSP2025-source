#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5000010;
int n,q;
string s[maxn][2];
string newstr;
int ans;
struct Trie{
	int ch[35];
	bool isEnd;
	string str;
}tr[maxn];
int newp=1;
string t,tt;
void Ins(string sp,string ssp){
	int u=1;
	for(char ch:sp){
		int c=ch-'a';
		if(!tr[u].ch[c]){
			tr[u].ch[c]=++newp;
		}
		u=tr[u].ch[c];
		
	}
	tr[u].isEnd=1;
	tr[u].str=ssp;
	return;
}
void solve(int x){
	int u=1;
	for(int i=x;i<(int)t.size();i++){
		int c=t[i]-'a';
		if(!tr[u].ch[c])break;
		u=tr[u].ch[c];
		if(tr[u].isEnd){
			int tot=0;
			newstr="";
			for(int j=0;j<(int)t.size();j++){
				if(j>=x&&j<=i){
					newstr+=tr[u].str[tot++];
				}
				else newstr+=t[j];
			}
			if(newstr==tt)++ans;
			break;
		}
	}
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		Ins(s[i][0],s[i][1]);
	}
	while(q--){
		cin>>t>>tt;
		ans=0;
		for(int i=0;i<(int)t.size();i++)solve(i);
		cout<<ans<<'\n';
	}
	return 0;
}
