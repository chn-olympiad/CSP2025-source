#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string a[200010],b[200010],x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(q--){
		ans=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++)
			if(x.find(a[i])==y.find(b[i])&&x.find(a[i])<x.size()){
				ans++;
				for(int j=x.find(a[i])+a[i].size();j<x.size();j++)if(x[j]!=y[j]){
					ans--;
					break;
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}
