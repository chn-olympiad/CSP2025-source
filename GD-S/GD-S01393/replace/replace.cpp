#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<"0\n";continue;}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(t1.size()<s1[i].size())continue;
			int pos=t1.find(s1[i]);
			if(pos!=t1.npos){
				bool ok=true;
				for(int j=0;j<pos;j++)
					if(t1[j]!=t2[j]){ok=false;break;}
				string tmp=t2.substr(pos,s1[i].size());
				if(s2[i]!=tmp)ok=false;
				for(int j=pos+s1[i].size();j<t1.size();j++)
					if(t1[j]!=t2[j]){ok=false;break;}
				ans+=ok;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}/*
听说学OI找不到npy
要是我不学了呢 
*/
