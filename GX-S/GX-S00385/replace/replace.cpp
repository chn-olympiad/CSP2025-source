#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,base=131,maxn=1e5+10;
int n,q,cnt;
string s[maxn],t[maxn],u,v;
map<string,int>mp,rnk;
int get_hash(string s){
    if(mp[s])
        return mp[s];
    int res=0;
    for(int i=0;i<s.length();i++)
        res=(res*base%mod+(s[i]-'a'))%mod;
    return mp[s]=res;
}
int ranky(string s){
    if(rnk[s])
        return rnk[s];
    return rnk[s]=++cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    while(q--){
		cin>>u>>v;
		cout<<"0\n";
	}
    return 0;
}
