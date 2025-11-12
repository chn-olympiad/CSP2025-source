#include<iostream>
#include<string>
using namespace std;
const int maxn=1e3+5;
const int maxl=1e3+5;
const int base=265;
int br[maxn][maxl],n,q,ans;
string s[maxn],f[maxn],t,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>f[i];
	}
	while(q--){
		cin>>t>>d;
		ans=0;
		for(int i=0;i<t.size();i++){
			for(int j=1;j<=n;j++){
				string g="";
				if(i+s[j].size()-1<t.size()){
					if(t.substr(i,s[j].size())==s[j]){
						if(i)g=t.substr(0,i);
						g+=f[j];
						g+=t.substr(i+s[j].size(),t.size()-i-s[j].size());
						if(g==d){
							ans++;
						}
					}
				} 
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
