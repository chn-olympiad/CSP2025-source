#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define ls u<<1
#define rs ls|1
using namespace std;
const int N=2e5+5;
string a[N*2];
vector<int> ne[N*2];
vector<int> sol(int id,string s){
	vector<int> res;
	int i=0;
	for(int j=1;j<s.length();j++){
		while(i&&a[id][i+1]!=s[j]) i=ne[id][i];
		if(a[id][i+1]==s[j]) i++;
		if(i==a[id].length()-1) res.push_back(j),i=ne[id][i];
		//cout<<i<<" ";
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q; cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>a[i+n],a[i]=" "+a[i],a[i+n]=" "+a[i+n];
	for(int i=1;i<=n*2;i++){
		ne[i].push_back(0);
		int f=0; ne[i].push_back(0);
		for(int j=2;j<a[i].length();j++){
			while(f&&a[i][f+1]!=a[i][j]) f=ne[i][f];
			if(a[i][f+1]==a[i][j]) f++;
			ne[i].push_back(f);
			//cout<<f<<" ";
		}
		//cout<<"\n";
	}
	while(q--){
		string x,y; cin>>x>>y,x=" "+x,y=" "+y;
		int mi=5000006,mx=0;
		for(int i=1;i<x.length();i++) if(x[i]!=y[i]){
			mi=min(mi,i),mx=max(mx,i);
		}
		int ans=0;
		for(int i=1;i<=n;i++) if(a[i].length()-1>=mx-mi+1){
			vector<int> r1=sol(i,x),r2=sol(n+i,y);
			int r=0;
			for(int p:r1){
				while(r<r2.size()&&r2[r]<p) r++;
				if(r==r2.size()) break;
				if(r2[r]==p) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1 1
aba aba
ababaabab a
*/
/*
2 1
xabcx xadex
ab ac
xabcx xadex
*/