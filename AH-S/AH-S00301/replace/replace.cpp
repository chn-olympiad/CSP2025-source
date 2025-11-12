#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	if(n*q<=100000000){
		while(q--){
			string x,y;
			cin>>x>>y;
			ll ans=0;
			for(int i=1;i<=n;i++){
				if(x.find(s1[i])!=string::npos){
					string x1=x;
					ll p=x.find(s1[i]);
					x1.erase(p,s1[i].size());
					x1.insert(p,s2[i]);
					if(x1==y){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	else{
		while(q--){
			string x,y;
			cin>>x>>y;
			cout<<"0\n";
		}
	}
	return 0;
}
