#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,p[5],q;
string s1[200005],s2[200005],t1[200005],t2[200005],t,tt,sl[200008],sr[200008];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	} 
	if(q==1){
		cin>>t>>tt;
		int rr=0;
		for(int i=0;i<t.size();i++){
			sl[i]=sl[i-1]+t[i];
		}
		for(int i=t.size()-1;i>=0;i--){
			sr[i]=t[i]+sr[i+1];
		}
			for(int i=1;i<=n;i++){
				int rr=0;
				while(sr[rr].find(s1[i])!=-1){
					int k=sr[rr].find(s1[i]);
					string x=sl[k-1]+s2[i]+t.substr(k+s2[i].size());
					rr=k+s2[i].size()+1;
					//cout<<i<<" "<<x<<"\n";
					if(x==tt) ans++;
				}	
			}
	
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
}
