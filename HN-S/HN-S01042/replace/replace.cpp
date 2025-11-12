#include<bits/stdc++.h>
using namespace std;
string s1,s2;
long long n,q,maxn,ans;
map<string,string>mp;
bool vis[10000000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
		long long size=s1.size();
		vis[s1.size()]=1,maxn=max(maxn,size);
	}
	for(long long i=1;i<=q;i++){
		cin>>s1>>s2;
		ans=0;
		for(long long j=1;j<=s1.size();j++){
			if(vis[j]){
				for(long long k=0;k<s1.size()-j+1;k++){
					string as,bs=s1.substr(k,j),cs;
					if(mp[bs]==""){
						continue;
					}
					if(k>0){
						as=s1.substr(0,k);
					}
					if(k+j<s1.size()){
						cs=s1.substr(j+k,s1.size()-k-j); 
					}
					if(as+mp[bs]+cs==s2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

