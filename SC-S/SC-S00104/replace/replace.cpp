#include<bits/stdc++.h>
#define LL long long
#define rep(i,k,n) for(LL i=k;i<=n;i++)
#define VI vector<LL>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	unordered_map<string,string> t;
	rep(i,1,n){string s1,s2;cin>>s1>>s2;t[s1]=s2;}
	while(q--){
		string s1,s2;cin>>s1>>s2;string s4=s1;LL ans=0;
		rep(i,0,s1.size()-1){
			rep(j,i,s1.size()-1){
				string s="";
				rep(p,i,j)s+=s1[p];
				if(t.count(s)){
					for(auto& c:t){
						if(c.first==s){
							int uy=0;
							rep(p,i,j){
								s4[p]=c.second[uy];
								uy++;}}}}
				if(s4==s2)ans++;
				s4=s1;}}
		cout<<ans<<"\n";}}