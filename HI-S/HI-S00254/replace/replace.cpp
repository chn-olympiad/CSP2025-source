#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T = 1;
	while(T--){
		int n,q;
		cin>>n>>q;
		for(int i = 1; i <= n; i++){
			cin>>a[i]>>b[i];
		}
		for(int l = 1; l <= q; l++){
			string u,v;
			cin>>u>>v;
			int ans = 0;
			for(int i = 1; i <= n; i++){
				if(u.size() < a[i].size()) continue;
				if(u.size() == a[i].size()){
					if(u==a[i] && v == b[i]) ans++;
					continue;
				}
				for(int j = 0; j <= u.size() - a[i].size(); j++){
					int flag = 1;
					for(int k = 0; k < a[i].size(); k++){
						if(u[j+k]!=a[i][k]){
							flag = 0;
							break;
						}
					}
					if(flag){
						string tmp = u;
						tmp.replace(j,a[i].size(),b[i]);
						if(tmp == v) ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
