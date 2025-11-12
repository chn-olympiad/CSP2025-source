#include<bits/stdc++.h>
using namespace std;
int n,q;
long long ans;
string s[200005][2];
map<string,bool> mp;
void bfs(string t,string t1){
	if(t==t1){
		++ans;
	}
	for(int i=1;i<=n;++i){
		bool pan=0;
		int w=0;
		for(int j=0;j+s[i][0].size()-1<t.size();++j){
			bool pan1=1;
			for(int k=j;k<=j+s[i][0].size()-1;++k){
				if(t[k]!=s[i][0][k-j]){
					pan1=0;
					break;	
				}
			}
			if(pan1){
				pan=1;
				w=j;
			}
			if(pan)break;
		}
		if(pan){
			string t2=t;
			for(int j=w;j<=w+s[i][0].size()-1;++j){
				t2[j]=s[i][1][j-w];
			}
			if(mp[t2])continue;
			bfs(t2,t1);
		}
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		ans=0;
		string t,t1;
		cin>>t>>t1;
		for(auto &e:mp){
			e.second=0;
		}
		bfs(t,t1);
		cout<<ans<<endl;
	}
	return 0;
}
