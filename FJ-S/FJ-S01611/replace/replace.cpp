#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#define mn 200005
using namespace std;
int n,q,sz,l,r,d,ans;
string s1,s2;
vector<int> f1[10000007],f2[10000007];
struct md{
	int l,r,d;
}f[mn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		sz=s1.size();
		d=0;
		for(int j=0;j<sz;j++){
			if(s1[j]=='b') l=j,d-=j;
			if(s2[j]=='b') r=sz-j-1,d+=j;
		}
		f1[d+5000001].push_back(l);
		f2[d+5000001].push_back(r);
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()) cout<<0<<endl;
		sz=s1.size();
		d=0;
		for(int j=0;j<sz;j++){
			if(s1[j]=='b') l=j,d-=j;
			if(s2[j]=='b') r=sz-j-1,d+=j;
		}
		sz=f1[d+5000001].size();
		ans=0;
		for(int j=0;j<sz;j++){
			if(l>=f1[d+5000001][j]&&r>=f2[d+5000001][j]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
