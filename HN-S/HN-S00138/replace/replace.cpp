#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5; 

int n,q,ans;
string a[maxn],b[maxn],u,v,t;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	} 
	if(n>=2000){
		while(q--){
			puts("0");
		}
		return 0;
	}
	while(q--){
		ans=0;
		cin>>u>>v;
		for(int i=1;i<=n;i++){
			for(int l=0;l+a[i].size()-1<u.size();l++){
				if(u.substr(l,a[i].size())==a[i]){
					t=u;
					for(int j=0,k=l;j<a[i].size();j++,k++){
						t[k]=b[i][j];
					}
					if(t==v){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
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
