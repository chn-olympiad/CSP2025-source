#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t;
int n;
int a[maxn][3];
/*
666这是第一题？蒟蒻哭了
没找到啥好的做法
我准备暴搜了
不会这次不到100吧 
提高组，我还是喜欢2024年的你 
*/
vector<char> p;
string s[1000005];
int q=0;
bool check(string x,char y){
	if(y=='0'){
		int cnt=0;
		for(int i=0;i<x.size();i++) if(x[i]=='0') cnt++;
		return cnt<n/2;
	}
	for(int i=0;i<x.size();i++) if(x[i]==y) return 0;
	return 1;
}
void dfs(string w){
	if(w.size()==n/2*3){
		s[++q]=w;
		return;
	}
	for(int i=0;i<p.size();i++){
		if(check(w,p[i])) dfs(w+p[i]);
	}
}
int ans=0;
void solve(){
	q=0,ans=0;
	p.clear();
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++) p.push_back(char(i+'0'));
	for(int i=1;i<=n/2;i++) p.push_back('0');
	dfs("");
	for(int i=1;i<=q;i++){
		string t=s[i];
		int sum=0;
		for(int j=0;j<t.size();j++){
			int res=t[j]-'0';
			int at=j/(n/2)+1;
			sum+=a[res][at];
		}
		ans=max(ans,sum);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
	return 0;
}
