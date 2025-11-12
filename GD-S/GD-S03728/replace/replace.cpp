#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct node{
	string x,y;
}s[N];
int n,k;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].y;
	}
	string a,b;
	while(k--){
		cin>>a>>b;
		int ans=0;
		if(a.size()>b.size()){
			cout<<0<<endl;
			continue;
		}
		int flag=0,tx=0,ty=0,f=1;
		for(int i=0;i<a.size();i++){
			if(a[i]==b[i]){
				if(flag) ty=i-1;
				continue;	
			}
			if(!flag){
				tx=i;
				flag=1;
			}
			if(ty!=0&&flag){
				f=0;
				break;
			}
		}
		int pos=ty-tx;
		string g;
		for(int i=0;i<=tx;i++){
			g+=a[i];
		}
		for(int i=1;i<=n;i++){
			if(a.size()<pos) continue;
			int ff=1;
			for(int j=0;j<tx;j++){
				g+=s[i].y.size();
			}
			for(int j=ty;j<a.size();j++){
				g+=a[i];
			}
			for(int j=0;j<a.size();j++){
				if(g[j]!=b[j]){
					ff=0;
					break;
				}
			}
			if(ff) ans++;
		}
		
		if(!f) cout<<0<<endl;
		else cout<<ans<<endl;
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de 
aa bb
xabcx xadex
aaaa bbbb

*/ 
