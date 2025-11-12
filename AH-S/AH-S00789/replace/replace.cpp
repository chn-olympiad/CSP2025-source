#include<bits/stdc++.h>
using namespace std;
int n,m;
string x,y,a[100005],b[100005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(m--){
		cin>>x>>y;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j+a[i].size()<=x.size();j++){
				if(x.substr(j,a[i].size())==a[i]&&x.substr(0,j)+b[i]+x.substr(j+a[i].size(),x.size()-j-a[i].size())==y) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
