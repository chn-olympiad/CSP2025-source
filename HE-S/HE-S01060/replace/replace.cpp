#include<bits/stdc++.h>
using namespace std;

long long n,q;
string x,y;
struct ss{
	string s,h;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].h;
	while(q--){
		long long f=0,ans=0;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]) f++;
		}
		for(int i=1;i<=n;i++){
			if(a[i].s.size()<f) continue;
			int t=x.find(a[i].s);
			while(t!=-1){
				string p=x;
				for(int j=0;j<a[i].h.size();j++) p[j+t]=a[i].h[j];
				if(p==y) ans++;
				t=x.find(a[i].s,t+1);
			}
		}
		cout<<ans<<"\n";
	} 	
	
	
	return 0;
}
