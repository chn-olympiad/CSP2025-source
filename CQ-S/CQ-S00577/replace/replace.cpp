#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=1e3+5;
int n,m,k;
int T;
string s1[N],s2[N];
signed main(){
	//ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(m--){
		string s,t;
		cin>>s>>t;
		int ans=0;
		for(int x=1;x<=n;x++){
			int j=0;
			if(s.find(s1[x])<s.size()){
				int i=s.find(s1[x]);
				string p="";
				for(int j=0;j<i;j++)p.push_back(s[j]);
				p=p+s2[x];
				for(int j=i+s1[x].size();j<s.size();j++)p.push_back(s[j]);
				if(p==t)ans++;
			}
		}
		cout<<ans<<'\n';
	}
}

