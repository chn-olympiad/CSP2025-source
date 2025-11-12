#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
struct node{
	string a,b;
}e[N];
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> e[i].a >> e[i].b; 
	}
	if(q>=200000){
		for(int i=1;i<=q;i++) cout << "0\n";
		return 0;
	}
	while(q--){
		string p,q;
		cin >> p >> q;
		int ans=0;
		for(int i=1;i<=n;i++){
			string t=e[i].a,tt=e[i].b;
			int pp=p.size(),ttt=t.size();
			for(int j=0;j+ttt-1<pp;j++){
				bool f=0;
				for(int k=j;k<j+ttt-1;k++){
					if(t[k-j]!=p[j]) {
						f=1;
						break;
					}
				}
				if(f==1){
					string g=p;
					for(int k=j;k<j+ttt-1;k++){
						g[j]=tt[k-j];
					}
					if(g==q) ans+=1;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
