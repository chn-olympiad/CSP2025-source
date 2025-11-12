#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string o,p;
		cin>>o>>p;
		for(int j=1;j<=n;j++){
			if(o.find(a[j])!=o.npos&&p.find(b[j])!=p.npos){
				if(o.find(a[j])==p.find(b[j])){
					if(o.erase(o.find(a[j]),a[j].size())==p.erase(p.find(b[j]),b[j].size())){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	} 
	return 0; 
} 