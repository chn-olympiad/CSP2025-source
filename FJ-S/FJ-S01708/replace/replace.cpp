#include <bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string s,ch;
queue <pair<string,string>> qu;
void check(int st){
	for(int i=1;i<=n;i++){
		string s1=qu.front().first,s2=qu.front().second;
		qu.pop();
		int len=s1.length();
		bool f=0;
		for(int j=0;j<len;j++){
			if(!(s[st+j]==s1[j]&&ch[st+j]==s2[j])){
				f=1;
				break;
			}
		}
		if(!f){
			for(int j=st+len;j<s.length();j++){
				if(s[j]!=ch[j]){
					f=1;
					break;
				}
			}
		}
		if(!f)ans++;
		qu.push(make_pair(s1,s2));
	}
}
void solve(){
	for(int i=0;i<s.length();i++){
		check(i);
		if(s[i]!=ch[i])break;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		qu.push(make_pair(s1,s2));
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>s>>ch;
		solve();
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
