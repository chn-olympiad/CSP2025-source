#include<bits/stdc++.h>
using namespace std;
int vis[5000005];
string s[5000005][3];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		vis[s[i][0].size()]=1;
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()||!vis[s1.size()]) cout<<0<<"\n";
		else{
			long long ans=0;
			for(int i=1;i<=n;i++){
				if(s1==s[i][0]&&s2==s[i][1]) ans+=2;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
