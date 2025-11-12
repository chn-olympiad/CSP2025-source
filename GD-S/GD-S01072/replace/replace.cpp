#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[N][2],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int l=0,r=t1.size()-1,ans=0;
		while(t1[l]==t2[l]) l++;
		while(t1[r]==t2[r]) r--;
		for(int i=1;i<=n;i++){
			int f1=s[i][0].find(t1.substr(l,r-l+1)),f2=s[i][1].find(t2.substr(l,r-l+1));
			if(f1==-1||f2==-1||l<f1||f1!=f2) continue;
			if(s[i][0].substr(0,f1)!=t1.substr(l-f1,f1)||s[i][1].substr(0,f1)!=t1.substr(l-f1,f1)) continue;
			if(s[i][0].substr(f1+r-l+1,s[i][0].size()-(f1+r-l+1))!=t1.substr(r+1,s[i][0].size()-(f1+r-l+1))) continue;
			if(s[i][1].substr(f1+r-l+1,s[i][0].size()-(f1+r-l+1))!=t2.substr(r+1,s[i][0].size()-(f1+r-l+1))) continue;
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
