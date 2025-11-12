#include <bits/stdc++.h>
using namespace std;

int n,q;
string s1[200007],s2[200007];
string t1,t2;
signed main(){
	freopen("replace.in" ,"r",stdin );
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			int sz=s1[j].size();
			for(int k=0;k+sz-1<t1.size();k++){
				if(t1.substr(k,sz)!=s1[j]) continue;
				int ss=t1.size()-k-sz;
				string L=t1.substr(0,k)+s2[j]+t1.substr(k+sz,ss);
				if(L==t2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
