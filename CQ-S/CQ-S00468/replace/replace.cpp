#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+5;
string p[N];
string g[N];
int cnt=0;
vector<int> q[27];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i]>>g[i];
		q[p[i][0]-'a'].push_back(i);
	}
	for(int i=1;i<=m;i++){
		string s,ss;
		cin>>s>>ss;
		int ans=0;
		int ll=s.size();
		for(int k=0;k<ll;k++){
			for(int o=0;o<q[s[k]-'a'].size();o++){	
				int l=q[s[k]-'a'][o];
				if(ll-k<p[l].size()){
					continue ;
				}
				string y=s;
				for(int j=k;j<=ll;j++){
					if(p[l][j-k]!=s[j])
						break ;
					y[j]=g[l][j-k];
					if(g[l][j-k]!=ss[j])
						break ;
				}
				if(y==ss)
					ans++;
			}
			if(s[k]!=ss[k])
				break ;
		}
		cout<<ans<<endl;
	}
	return 0;
}
