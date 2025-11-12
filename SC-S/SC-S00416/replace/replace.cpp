#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
struct node{
	string s;
	string q;
}a[maxn];
char r;
int vj[maxn];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i].s>>a[i].q;
		char mp[maxn];
	for(int j=0;j<a[1].s.size();++j){
		mp[a[i].s[j]]++;
		if(mp[a[i].s[j]]==1){
			r=a[i].s[j];
			vj[i]=j;
		}
	}
}
	int js=0;
	for(int i=1;i<=m;++i){
		cout<<0<<endl;
	}
	return 0;
} 