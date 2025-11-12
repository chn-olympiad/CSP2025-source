#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
string s[N][3];
int n,Q;
string a,tgt;
map<string,int>mp;
int dfs(int u,string a){
	if(u==3) return 0;
	if(a==tgt) return 1;
	//cout<<u<<" "<<a<<"\n";
	int res=0;
	for(int i=1;i<=n;i++){
		string L="",R=a;
		for(int l=0;l<a.size();l++){
			string R="",str="";
			for(int _=l;_<a.size();_++) R+=a[_];
			for(int r=l;r<a.size();r++){
				str+=a[r];R.erase(R.begin());
				if(str==s[i][1]){
					res+=dfs(u+1,L+s[i][2]+R);
					break;
				}
			}
			L+=a[l];
		}
	}
	return res;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>Q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];	
	while(Q--){
		cin>>a>>tgt;
		cout<<dfs(1,a)<<"\n";
	}
	return 0;
}