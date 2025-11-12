#include <bits/stdc++.h>
using namespace std;
int n,m;
string a[200005],b[200005],x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(m--){
		cin>>x>>y;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==x&&b[i]==y) ans++;
			else if(a[i].size()<=x.size()){
				for(int j=0;j<x.size()-a[i].size();j++){
					string s=x.substr(j,a[i].size());
					string t=y.substr(j,a[i].size());
					if(s==a[i]&&t==b[i]){
						s=x.substr(0,j),t=y.substr(0,j);
						if(s==t){
							s=x.substr(j+a[i].size(),x.size()-a[i].size());
							t=y.substr(j+a[i].size(),x.size()-a[i].size());
							if(s==t) ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
