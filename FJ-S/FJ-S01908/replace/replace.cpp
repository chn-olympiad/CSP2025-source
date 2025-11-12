#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=2e5+5;
bool check(string s,int qi,string ti,string mb){
	for(int i=0;i<qi;i++) if(s[i]!=mb[i]) return false;
	for(int i=qi;i<qi+ti.size()-1;i++) if(ti[i]!=mb[i]) return false;
	for(int i=qi+ti.size();i<s.size();i++) if(s[i]!=mb[i]) return false;
	return true;
}
ll n,q;
string s1[maxn],s2[maxn];
vector<ll> net[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=s1[i].size();j++) net[i].push_back(0);
		s1[i]=" "+s1[i];
		for(int j=1;j<s1[i].size();j++){
			while(s1[i][net[i][j]+1]==s1[i][j+1]) ;
		}
	}
	return 0;
}
