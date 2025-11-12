#include<bits/stdc++.h>
using namespace std;
const int inf=1e6+10;
int nxt[inf][26];
vector<int> id[inf];
string s[inf>>3];
int n,q;
int tot;
inline void add(string &str,int ii){
	int p=0,len=str.length();
	for(int i=0;i<len;i++){
		if(!nxt[p][str[i]-'a']){
			nxt[p][str[i]-'a']=++tot;
		}
		p=nxt[p][str[i]-'a'];
	}
	id[p].emplace_back(ii);
}
int ans=0;
inline void sol(string &a,string &b){
	int p=0,len=a.length();
	string kep="";
	for(int i=0;i<len;i++){
		if(!nxt[p][a[i]-'a']){
			break;
		}
		p=nxt[p][a[i]-'a'];
		kep.push_back(b[i]);
		if(id[p].size()){
			for(auto o:id[p]){
				ans+=(s[o]==kep);
			}
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	string k1,k2;
	for(int i=1;i<=n;i++){
		cin>>k1>>s[i];
		add(k1,i);
	}
	string kk1="",kk2="";
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>k1>>k2;
//		int len=k1.length();
//		for(int l=0;l<len;l++){
//			kk1="";
//			kk2="";
//			for(int k=l;k<len;k++){
//				kk1.push_back(k1[k]);
//				kk2.push_back(k2[k]);
//			}
//			sol(kk1,kk2);
//		}
		cout<<ans<<'\n';
	}
}
