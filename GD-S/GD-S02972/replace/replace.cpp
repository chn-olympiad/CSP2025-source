#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,q;
ll ans,d;
string s[N],t[N],a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	while(q--){
		cin>>a>>b;
		ans=0;
		d=0;
		for(int i=0;i<(int)a.size();i++){
			if(a[i]!=b[i]) d++;
		}
		for(int i=0;i<(int)a.size();i++){
			for(int j=1;j<=n;j++){
				ll df=0;
				if(i+(int)s[j].size()-1>=(int)a.size()) continue;
				for(int k=0;k<(int)s[j].size();k++){
					if(i+k>=(int)a.size()) break;
					if(s[j][k]!=a[i+k]||t[j][k]!=b[i+k]) break;
					if(a[i+k]!=b[i+k]) df++;
					if(k+1==(int)s[j].size()&&df==d) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
