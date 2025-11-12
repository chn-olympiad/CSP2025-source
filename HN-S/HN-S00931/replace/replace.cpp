#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=2e5+10; 
int n,q,vis[N];
map<string,int> mp,dp;
string x,y,an[N][3];
int dfs(string s,int fqs,int fzd){
	if(dp[s]) return dp[s];
	if(s==y) return 1;
	int sum=0;
	string qs="";
	for(int i=0;i<s.size();i++){
		string fs="";
		int j=i;
		while(j<s.size()){
			fs+=s[j];
			if(mp[fs]&&!vis[mp[fs]]&&i!=fqs&&j!=fzd){ 
				string hs="";
				int bh=mp[fs];
				for(int k=j+1;k<s.size();k++) hs+=s[k];
//				cout<<"x="<<qs<<" y`="<<an[bh][2]<<" z="<<hs<<"  ---->"<<qs+an[bh][2]+hs<<endl;
				vis[bh]=1;
				sum+=dfs(qs+an[bh][2]+hs,i,j);
				vis[bh]=0;
			}
			++j;
		}
		qs+=s[i];
	}
	dp[s]=sum;
	return sum;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		 cin>>an[i][1]>>an[i][2];
		 mp[an[i][1]]=i;
	}
	while(q--){
		cin>>x>>y;
		cout<<dfs(x,-1,-1)<<endl;
	}
	return 0;
}
