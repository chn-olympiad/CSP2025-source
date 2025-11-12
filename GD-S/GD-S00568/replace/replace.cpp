#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q;
string t1,t2;
struct {
	string a,b;
} a[maxn];
void in() {
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>a[i].a>>a[i].b;
	}
}
bool pd(string a,int l,int r,string b){
	if((r-l+1)!=int(b.size()))return 0;
	for(int i=l,j=0;i<=r;i++,j++){
		if(a[i]!=b[j])return 0;
	}
	return 1;
}
int dfs(int x,string ns,int las) {
	int res=0;
	if(x==int(t2.size())) {
		return ns==t2;
	}
	for(int i=1; i<=n; i++) {
		if(pd(ns,las,x,a[i].a)&&pd(t2,las,x,a[i].b)) {
			string nes=ns;
			for(int i=las,j=0;i<=x;i++,j++)nes[i]=a[i].b[j];
			res+=dfs(x+1,nes,x+1);
		}
	}
	res+=dfs(x+1,ns,las);
	return res;
}
int solve() {
	return dfs(0,t1,0);
}
int main() {
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	in();
	for(int i=1; i<=q; i++) {
		cin>>t1>>t2;
		cout<<solve()<<"\n";
	}
	return 0;
}

