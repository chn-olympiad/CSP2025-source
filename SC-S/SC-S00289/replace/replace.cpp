#include<bits/stdc++.h>
using namespace std;
#define int long long
struct p{
	string s1,s2;
} a[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--){
		int cnt=0;
		string sx,sy;
		cin>>sx>>sy;
		if(sx.size()!=sy.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<sx.size()-a[i].s1.size()+1;j++){
				if(sx.substr(j,a[i].s1.size())==a[i].s1){
					if(sx.substr(0,j)+a[i].s2+sx.substr(j+a[i].s1.size(),sx.size()-j-a[i].s1.size())==sy){
						cnt++;
						break;
					}
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
