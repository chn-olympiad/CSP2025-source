#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=5e6+10;
int cnt=0;
map<pair<string,string>,int> mp;
vector<pair<string,string> > v[M];
struct node{
	string s1="",s2="",f="",m1="",m2="",l="";
}s[N];
bool check(string x1,string y1,string x2,string y2){
	int lenx1=x1.size(),leny1=y1.size();
	if(leny1>lenx1) return 0;
	for(int i=1;i<=leny1;++i) if(x1[lenx1-i]!=y1[leny1-i]) return 0;
	int lenx2=x2.size(),leny2=y2.size();
	if(leny2>lenx2) return 0;
	for(int i=0;i<leny2;++i) if(x2[i]!=y2[i]) return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >>n>>q;
	for(int i=1;i<=n;++i){
		cin >>s[i].s1>>s[i].s2;
		if(s[i].s1==s[i].s2) continue;
		int j1=0,len=s[i].s1.size(),j2=len-1;
		for(;j1<len;++j1){
			if(s[i].s1[j1]==s[i].s2[j1]) s[i].f+=s[i].s1[j1];
			else break;
		}	
		for(;j2>=0;--j2){
			if(s[i].s1[j2]==s[i].s2[j2]) s[i].l=s[i].s1[j2]+s[i].l;
			else break;
		}
		for(int j=j1;j<=j2;++j){
			s[i].m1+=s[i].s1[j];
			s[i].m2+=s[i].s2[j];
		}
		if(mp[{s[i].m1,s[i].m2}]==0) mp[{s[i].m1,s[i].m2}]=++cnt;
		v[mp[{s[i].m1,s[i].m2}]].push_back({s[i].f,s[i].l});
	}
	while(q--){
		string u,vv,left,mid1,mid2,right;
		cin >>u>>vv;
		int j1=0,len=u.size(),j2=len-1;
		for(;j1<len;++j1){
			if(u[j1]==vv[j1]) left+=u[j1];
			else break;
		}
		for(;j2>=0;--j2){
			if(u[j2]==vv[j2]) right=u[j2]+right;
			else break;
		}
		for(int j=j1;j<=j2;++j) mid1+=u[j],mid2+=vv[j];
		int id=mp[{mid1,mid2}],ans=0;
		if(id==0){
			cout <<0<<"\n";
			continue;
		}
		for(auto i:v[id]) if(check(left,i.first,right,i.second)) ans++;
		cout <<ans<<"\n";
	}	
	return 0; 
} 
