#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e5+10;
string s[N][2];
string tx,ty;
map<string,bool>vis;
int n,q;
int ans;
string *p;
void dfs(string str){
//	if(str==ty){
//		++ans;
//		return;
//	}
//	if(vis[str]) return;
//	vis[str]=1;
//	cout<<str<<'\n';
	for(int i=0;i<str.size();++i){//L2
		for(int j=0;j<n;++j){//n
			if(i+s[j][0].size()-1>=str.size()) continue;
			if(str[i]==s[j][0][0]){
				bool flag=1;
				for(int k=0;k<s[j][0].size();++k){//l1
					if(str[i+k]!=s[j][0][k]){
						flag=0;
						break;
					}
				}
				if(flag){
//					p=new string;
//					*p=str;
					string _=str;
					for(int k=0;k<s[j][0].size();++k){
						str[i+k]=s[j][1][k];
					}
					if(str==ty) ++ans;
//					dfs(str);
					str=_;
//					delete p;
				}
//				if(s[j][0]=="bc") cout<<"\ncheck\n";
			}
		}
	}
}
bool check(string&__str){
	int x=0,y=0;
	for(int i=0;i<__str.size();++i){
		if(__str[i]!='a' and __str[i]!='b') return false;
		if(x>1 and y>1) return false;
		if(__str[i]=='a') ++x;
		else ++y;
	} 
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("ans.txt","w",stdout);
//	bool flag=1;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
//		if(flag) flag=check(s[i][0]);
//		if(flag) flag=check(s[i][0]);
	}
	while(q--){
		ans=0;
		bool f=1;
//		cout<<'\n';
		cin>>tx>>ty;
//		if(f) f=check(tx);
//		if(f) f=check(ty);
//		if(f){
//			for(int i=0;i<n;++i){
//				if(s[i][0]==tx and s[i][1]==ty) ++ans; 
//			}
//		}
//		else dfs(tx);
		dfs(tx);
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
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



3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
