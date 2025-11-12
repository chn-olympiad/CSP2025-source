#include<bits/stdc++.h>
#define MAXN 2000
using namespace std;
string p[MAXN],q[MAXN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>p[i]>>q[i];
	}
	while(m--){
		string a,b;
		cin>>a>>b;
		int res=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<a.size()-p[i].size();++j){
				if(a.substr(j,j+p[i].size()-1)==q[i]&&a.substr(0,j)+q[i]+a.substr(j+p[i].size(),a.size()-1)==b){
					++res;
				}
			}
		}
		cout<<res<<endl;
	} 
	return 0;
}
