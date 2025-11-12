#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
int n,q,vis[N];
string s[N],s2[N];
string x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i]>>s2[i];
	}
	while(q--){
		cin>>x>>y;
		int m=x.size();
		int las=-1,tag=1;
		for(int i=0;i<m;++i) vis[i]=0;
		for(int i=0;i<m;++i){
			if(x[i]!=y[i]){
				vis[i]=1;
				if(las!=-1&&las!=i-1){
					tag=0;
					break;
				}
			}
		}
		if(!tag){
			cout<<"0\n";
			continue;
		}
		int l=-1,r=-1;
		for(int i=0;i<m;++i){
			if(vis[i]){
				if(l==-1) l=i;
				r=i;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			int j=i;
			if((int)s[i].size()<r-l+1) continue;
			if((int)s2[j].size()<r-l+1||(s2[j].size()!=s[i].size())) continue;
			int tag=0;
			for(int t=0;t<m;++t){
				int fg=1;
				for(int k=0;k<=r-l;++k){
					if(s[i][k]!=x[t+k]) fg=0;
				}
				if(fg&&t+(int)s[i].size()-1>=r) tag=1; 
			}	
			if(!tag) continue; 
			tag=0;
			for(int t=0;t<m;++t){
				int fg=1;
				for(int k=0;k<=r-l;++k){
					if(s2[j][k]!=y[t+k]) fg=0;
				}
				if(fg&&t+(int)s2[j].size()-1>=r) tag=1;
			}
			cnt+=tag;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex


*/