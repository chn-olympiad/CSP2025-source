#include <bits/stdc++.h>
using namespace std;
map<string,map<string,int> >cnt,bz; 
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i) {
		string a,b,u="",v="";
		cin>>a>>b;
		bz[a][b]=1;
		int l,r;
		for(l=0;l<a.size()&&a[l]==b[l];++l)
		for(r=b.size()-1;r>=0&&a[r]==b[r];--r);
		for(int j=l;j<=r;++j) u+=a[j],v+=b[j];
		cnt[u][v]++;
	}
	for(int i=1;i<=q;++i) {
		string a,b,u="",v="";
		cin>>a>>b;
		int l,r;
		for(l=0;l<a.size()&&a[l]==b[l];++l)
		for(r=b.size()-1;r>=0&&a[r]==b[r];--r);
		for(int j=l;j<=r;++j) u+=a[j],v+=b[j];
		cout<<(bz[u][v]==1?cnt[u][v]+1:cnt[u][v])<<endl;
	}
} 
