#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,flag;
string s[N],ss[N],t,tt;
int readd(){
	int c=getchar(),k=0,f=1;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+(c^48);
	return k*f;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=readd();
	q=readd();
	for(int i=1; i<=n; i++) {
		cin>>s[i]>>ss[i];
	}
	while(q--) {
		cin>>t>>tt;
		long long ans=0;
		for(int i=1; i<=n; i++) {
			if(t.find(s[i])<s[i].size()){
				string ns=t;
				int pos=t.find(s[i]);
				ns.erase(pos,s[i].size());
				ns.insert(pos,ss[i]); 
				if(ns==tt) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
