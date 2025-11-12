#include<bits/stdc++.h>
using namespace std;
int n,q;
string l[200005],r[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=1;i<=n;i++){
			int xb=-1;
			while(1){
				xb=a.find(l[i],xb+1);
				if(xb==-1)break;
				string x=a.substr(0,xb),z;
				z=a.substr(xb+l[i].size(),a.size()-x.size()-l[i].size());
				if(b==x+r[i]+z)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
