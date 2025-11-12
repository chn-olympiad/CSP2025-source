#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
int n,m,ans;
string a,b;
pair<string,string> t[MAXN];
void slove();
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
//	cin>>T;
	while(T--){
		slove();
	}
	return 0;
}
void slove(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i].first>>t[i].second;
	}
	while(m--){
		cin>>a>>b;
		ans=0;
		for(int l=0;l<a.size();l++){
			for(int r=l;r<a.size();r++){
				string y="",x="",z="";
				for(int i=0;i<l;i++){
					x+=a[i];
				}
				for(int i=r+1;i<a.size();i++){
					z+=a[i];
				} 
				for(int i=l;i<=r;i++){
					y+=a[i];
				}
				for(int i=1;i<=n;i++){
					if(y==t[i].first){
						if(x+t[i].second+z==b) ans++;
					}
				}
			}
		}	
		cout<<ans<<'\n';
	}
	return ;
}
