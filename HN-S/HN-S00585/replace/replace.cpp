#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
int n,q,sg;
string s[200001],t[200001],g;
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i]>>t[i];
	while(q--){
		string gd;
		cin>>gd>>g;
		sg=0;
		int l=gd.size();
		for(int i=1;i<=n;i++){
			int ls=s[i].size();
			for(int j=0;j+ls-1<l;j++){
				int f1=1;
				for(int k=0;k<j;k++)
					if(gd[k]!=g[k]){
						f1=0;
						break;
					} 
				if(!f1)continue;
				for(int k=j+ls;k<l;k++)
					if(gd[k]!=g[k]){
						f1=0;
						break;
					}
				if(!f1)continue;
				for(int k=j;k<=j+ls-1;k++)
					if(s[i][k-j]!=gd[k]||t[i][k-j]!=g[k]){
						f1=0;
						break;
					}
				if(!f1)continue;
				sg++;
			}
		}
		cout<<sg<<endl;
	}
} 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	while(T--)solve();
	return 0;
}
