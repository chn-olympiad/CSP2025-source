#include<bits/stdc++.h>
using namespace std;
string s[200005],t[200005],thx[200005],thy[200005];
int n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>s[i]>>t[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>thx[i]>>thy[i];
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(s[i].find(thx[j],0)!=18446744073709551615&&s[i].size()>thx[i].size()){
				string ls=s[i];
				int k=s[i].find(thx[i],0);
				ls.erase(k,thx[i].size());
				ls.insert(k,thy[i]);
				if(ls==t[i])ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
