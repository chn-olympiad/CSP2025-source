#include<bits/stdc++.h>
using namespace std;
int n,q;
string s,ss;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s>>s;
	for(int i=1;i<=q;i++){
		cin>>s>>ss;
		int len1=s.size(),len2=ss.size();
		if(len1!=len2) cout<<0<<endl;
		int ans=0;
		for(int i=0;i<len1;i++){
			if(s[i]!=ss[i]) ans++;
		}
		if(ans!=len1) cout<<ans<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
