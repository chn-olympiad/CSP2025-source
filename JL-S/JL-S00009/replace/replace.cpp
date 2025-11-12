#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string s1[200010],s2[200010],t1[200010],t2[200100];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;++i){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;++i){
		cin>>t1[i]>>t2[i];
	}
	for(int i=0;i<q;++i){
		int ans=0;
		for(int j=0;j<n;++j){
			int p=t1[i].find(s1[j]);
			string s=t1[i];
			if(p!=-1){
				s.replace(p,s1[j].size(),s2[j]);
				if(s==t2[i])ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
