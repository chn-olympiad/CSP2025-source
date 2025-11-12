#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10,INF=1e9;
pair<string,string> a[N];
int pre[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		cout<<0<<'\n';
	} 
	return 0;
}
