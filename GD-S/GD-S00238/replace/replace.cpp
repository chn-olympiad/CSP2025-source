#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,s[200005],e[200005],siz[200005],pcnt;
string s1[200005],s2[200005],str1,str2,t1,t2;
map<pair<string,string>,int>m;
vector<int>jl[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s[i]=-1;
		siz[i]=s1[i].size();
		for(int j=0;j<siz[i];j++){
			if(s1[i][j]!=s2[i][j]){
				if(s[i]==-1) s[i]=j;
				e[i]=j;
			}
		}
		str1="",str2="";
		for(int j=s[i];j<=e[i];j++){
			str1+=s1[i][j];
			str2+=s2[i][j];
		}
		if(!m.count(make_pair(str1,str2))) m[make_pair(str1,str2)]=pcnt++;
		jl[m[make_pair(str1,str2)]].push_back(i);
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int st=-1,ed;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				if(st==-1) st=j;
				ed=j;
			}
		}
		str1="",str2="";
		for(int j=st;j<=ed;j++){
			str1+=t1[j];
			str2+=t2[j];
		}
		if(!m.count(make_pair(str1,str2))){
			cout<<"0\n";
			continue;
		}
		int ans=0,now=m[make_pair(str1,str2)],tsz=t1.size();
		for(int i=0;i<jl[now].size();i++){
			int x=jl[now][i];
			if(s[x]>st||(siz[x]-e[x])>(tsz-ed)) continue;
			bool flag=true;
			for(int j=s[x]-1,k=st-1;j>=0;j--,k--){
				if(s1[x][j]!=t1[k]){
					flag=false;
					break;
				}
			}
			for(int j=e[x]+1,k=ed+1;j<siz[x];j++,k++){
				if(s1[x][j]!=t1[k]){
					flag=false;
					break;
				}
			}
			if(flag) ans++;
		}
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
//May the subtasks be full of water.
