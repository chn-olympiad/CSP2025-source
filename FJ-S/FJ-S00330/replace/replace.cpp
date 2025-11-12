#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n,q,ans;
string a[200005],b[200005];
map<string,string>g;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		g[a[i]]=b[i];
	}
	while(q--){
		ans=0;
		string m,n;
		cin>>m>>n;
		LL l=-1,r=m.size();
		for(int i=0;i<m.size();i++){
			if(l==-1&&m[i]!=n[i]) l=i; 
		}
		for(int i=m.size()-1;i>=0;i--){
			if(r==m.size()&&m[i]!=n[i]) r=i;
		}
		if(l==-1){
			cout<<0<<endl;
			continue;
		}
		else{
			string p="",q="";
			for(int i=l;i<=r;i++) p+=m[i],q+=n[i];
			if(!g[p].empty()) if(g[p]==q) ans++;
			for(int i=l-1;i>=0;i--){
				p=m[i]+p,q=n[i]+q;
				if(!g[p].empty()) if(g[p]==q) ans++;
			}
			for(int i=r+1;i<m.size();i++){
				p=p+m[i],q=q+n[i];
				if(!g[p].empty()) if(g[p]==q) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
