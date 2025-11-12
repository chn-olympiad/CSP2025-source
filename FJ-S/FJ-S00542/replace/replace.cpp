#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,q;
string s[2][N];
string t_1,t_2;
int check(string x,string y){
	int len=x.size();
	vector<pair<int,int>> ve;
	for(int i=1;i<=n;++i){
		int ln=s[0][i].size();
		vector<int> pi(ln,0);
		for(int k=1;k<ln;++k){
			int j=pi[k-1];
			while(j>0&&s[0][i][k]!=s[0][i][j]) j=pi[j-1];
			if(s[0][i][k]==s[0][i][j]) ++j;
			pi[k]=j;
		}
		int j=0;
		for(int l=0;l<len;++l){
			while(j>0&&x[l]!=s[0][i][j]) j=pi[j-1];
			if(x[l]==s[0][i][j]) ++j;
			if(j>=ln){
//				cout<<i<<" "<<l<<"\n";
				ve.push_back({i,l-ln+1});
			}
		}
	}
	int cnt=0;
	for(int i=0;i<ve.size();++i){
		int j=ve[i].first;
		int l=ve[i].second;
//		cout<<j<<" "<<l<<"\n";
		string t=x;
		x.replace(l,s[0][j].size(),s[1][j]);
//		cout<<x<<"\n";
		if(x==y) ++cnt;
		x=t;
	}
	return cnt;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[0][i]>>s[1][i];
	}
	while(q--){
		cin>>t_1>>t_2;
		cout<<check(t_1,t_2)<<"\n";
	}
	return 0;
}
