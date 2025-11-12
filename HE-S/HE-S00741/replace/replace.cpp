#include<bits/stdc++.h>
#define fi first
#define se second
const int N = 2e5+10;
using namespace std;
int n,q; string ss,sss;
pair<string,string>s[N];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>ss>>sss;
		s[i]={ss,sss};
	}
	while(q--) {
		string t,tt,ttt={},op={};int l=-1,r=0,ans=0;
		cin>>t>>tt;
		if(t.size()!=tt.size()) {puts("0");continue;}
		for(int i=0;i<(int)t.size();i++) 
			if(t[i]!=tt[i]) {if(l==-1) l=i,r=i;else r=i;}
		for(int i=1;i<=n;i++) {
			for(int j=0;j<(int)t.size();j++) {
				if(t[j]==s[i].fi[0]) {
					op=ttt; 
					int flag=0,id=0;
					for(int k=j;k<(int)t.size()&&id<(int)s[i].se.size();k++,id++) {
						if(t[k]!=s[i].fi[id]||s[i].se[id]!=tt[k]) {
							flag=1;break;
						} else op=op+s[i].se[id];
					}
					if(!flag) {
						if((int)op.size()>=r+1) {
							ans++;
						}
					}
					op={};
				} ttt=ttt+t[j];
				if(t[j]!=tt[j]) {break; cout<<j<<endl;}
			} ttt={};
		} printf("%d\n",ans);
	}
	return 0;
}
