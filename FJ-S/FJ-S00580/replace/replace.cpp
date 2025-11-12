#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+5;
int n,m,ans;
string s[MAXN],t[MAXN],x,y;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	while(m--){
		cin>>x>>y;
		ans=0;
		for(int i=1;i<=n;i++){
			string k=x;
			int r=k.find(s[i]);
			if(r==-1) continue;
			for(int j=r;j<=r+s[i].size()-1;j++){
				k[j]=t[i][j-r];
			}
			if(k==y) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
