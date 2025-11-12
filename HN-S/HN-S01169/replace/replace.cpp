#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N],t[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i]>>t[i];
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			int x=t1.find(s[i]);
			string tmp;
			if(x>0)tmp+=t1.substr(0,x);
			if(x!=-1)tmp+t[i]+t1.substr(x+t[i].size(),t1.size()-s[i].size()-x);
			if(tmp==t2)ans++;
		}	
		cout<<ans<<'\n';
	}
	return 0;
}

