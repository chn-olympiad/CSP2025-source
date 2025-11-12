#include<bits/stdc++.h>
using namespace std;
#define int long long
string t1,t2,t,tt,s1[200010],s2[200010];
int n,q,ans;
int x,y,u;
bool tot,f;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		ans=0;tot=0;f=0;
		t.clear();tt.clear();
		x=t1.size(),y=t2.size();
		if(x!=y){cout<<0<<'\n';continue;}
		for(int i=0;i<x;i++){
			if(t1[i]!=t2[i]){
				if(t1[i-1]==t2[i-1]&&tot){
					f=1;break;
				}
				tot=1;t+=t1[i];tt+=t2[i];
			}
		}
		if(f){
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(t1==s1[i]&&t2==s2[i]){ans++;continue;}
			u=s1[i].size();
			if(u>=x) continue;
			if(s1[i].find(t)==-1||s2[i].find(tt)==-1) continue;
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
