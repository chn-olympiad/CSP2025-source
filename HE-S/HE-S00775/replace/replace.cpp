#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int n;
string s[N];

struct kmp{
	string s,t;
	int n,m,nxs[N],nxt[N];
	void init(string a,string b){
		s=a;
		n=s.size();
		s="#"+s;
		t=b;
		m=t.size();
		t="#"+t;
		for(int i=2,j=0;i<=n;i++){
			while(j&&s[i]!=s[j+1]) j=nxs[j];
			if(s[i]==s[j+1]) j++;
			nxs[i]=j;
//			cout<<nxs[i]<<" ";
		}
//		cout<<"\n";
		for(int i=2,j=0;i<=m;i++){
			while(j&&t[i]!=t[j+1]) j=nxt[j];
			if(t[i]==t[j+1]) j++;
			nxt[i]=j;
//			cout<<nxt[i]<<" ";
		}
//		cout<<"\n";
	}
	int find(string a,string b,int k){
		a="$"+a;
		b="$"+b;
		for(int is=1,it=1,js=0,jt=0;is<=k&&it<=k;is++,it++){
			while(js&&a[is]!=s[js+1]) js=nxs[js];
			while(jt&&b[it]!=t[jt+1]) jt=nxt[jt];
			if(a[is]==s[js+1]) js++;
			if(b[it]==t[jt+1]) jt++;
			if(js==n){
				if(jt==m){
					for(int i=it+1;i<=k;i++){
						if(a[i]!=b[i]) return 0;
					}
					return 1;
				}
				js=nxs[js];
			}
			if(jt==m){
				jt=nxt[jt];
			}
		}
		return 0;
	}
}a[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		a[i].init(s,t);
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i].find(s,t,s.size());
		}
		cout<<ans<<"\n";
	}
	return 0;
}

