#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
string s[200100],ss[200100];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i]>>ss[i];
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		string c,d;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a.find(s[i])<a.size()){
				int t=a.find(s[i]);
				if(t==b.find(ss[i])){
					c=a;
					d=b;
					int l=s[i].size();
					c.erase(t,l);
					d.erase(t,l);
					if(c==d)
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
