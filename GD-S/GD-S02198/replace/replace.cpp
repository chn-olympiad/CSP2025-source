#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
string a[200005],b[200005];
int n,q,ans; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++){
		string x,y;cin>>x>>y;
		int l=-1,r=0;
		for(int j=0;j<x.size();j++){
			if(x[j]!=y[j]&&l==-1)l=j;
			if(x[j]!=y[j])r=j;
		}
		for(int j=1;j<=n;j++){
			if(x.find(a[j])!=-1&&x.find(a[j])==y.find(b[j])){
				int lx=x.find(a[j]),rx=lx+a[j].size()-1;
				if(lx<=l&&rx>=r)ans++;
			}
		}
		cout<<ans<<endl;
		ans=0; 
	}
	return 0;
} 
