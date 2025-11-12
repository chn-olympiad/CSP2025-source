#include <bits/stdc++.h> 
using namespace std;
const int N=2e5+10;
string t[N],g[N];
int n,q;
int main(){
	freopen("replace.in","r",stdin) ;
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>g[i];
	}
	for(int i=1;i<=q;i++){
		string s,ss;
		cin>>s>>ss;
		int nn=s.size();int ans=0;
		for(int i=0;i<nn;i++){
			for(int j=i;j<nn;j++){
				
				int lflag=1,rflag=1;
				string ms="";
				string mss="";
				for(int k=0;k<i;k++){
					if(s[k]!=ss[k]) lflag=0;
				}
				for(int k=j+1;k<nn;k++){
					if(s[k]!=ss[k]) rflag=0;
				}
				if(!(lflag&&rflag)) continue;
				for(int k=i;k<=j;k++){
					ms+=s[k];
					mss+=ss[k];
				}
				for(int k=1;k<=n;k++){
					if(t[k]==ms&&g[k]==mss) ans++;
				}
			}
		}cout<<ans<<"\n";
	}
	return 0;
}
