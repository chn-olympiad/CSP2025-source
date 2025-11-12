#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=2005;
int n,q,gap[N],fail[M/2][M];
string s1[N],s2[N];
unordered_map<int,vector<pair<int,int>>>ct;
void solve1(){
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(;q;q--){
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int l=0,r=t2.size()-1;
		while(t1[l]==t2[l])l++;
		while(t1[r]==t2[r])r--;
		int res=0;
		for(int i=0;i<=l;i++){
			for(int j=1;j<=n;j++){
				if(t1.size()-i<s1[j].size()||i+s1[j].size()-1<r)continue;
				if(t1.substr(i,s1[j].size())==s1[j]&&t2.substr(i,s2[j].size())==s2[j])res++;
			}
		}
		cout<<res<<'\n';
	}
}
void solve2(){
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int l,r;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b'){
				l=j;break;
			}
		}
		for(int j=0;j<s2[i].size();j++){
			if(s2[i][j]=='b'){
				r=j;break;
			}
		}
		gap[i]=l-r;
		if(l<r)ct[l-r].push_back({l,s1[i].size()-r-1});
		else ct[l-r].push_back({s1[i].size()-l-1,r});
	}
	for(;q;q--){
		string t1,t2;cin>>t1>>t2;
		int l,r;
		for(int i=0;i<t1.size();i++){
			if(t1[i]=='b'){
				l=i;break;
			}
		}
		for(int i=0;i<t2.size();i++){
			if(t2[i]=='b'){
				r=i;break;
			}
		}
		int res=0;
		if(l<r){
			for(auto it:ct[l-r]){
				if(it.first<=l&&it.second<=t1.size()-r-1)res++;
			}
		}else {
			for(auto it:ct[l-r]){
				if(it.first<=t1.size()-l-1&&it.second<=r)res++;
			}
		}
		cout<<res<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n<=1e2&&q<=200)solve1();
	else solve2();
	
	return 0;
} 
