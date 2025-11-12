#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,q;
struct node{
	string fi,se;
}lj[200005];
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>lj[i].fi>>lj[i].se;
	while(q--){
		cin>>a>>b;
		string c=a;
		ans=0;
		for(int i=0;i<a.size();i++){
			for(int j=1;j<=n;j++){
				if(lj[j].fi[0]!=b[i])continue;
				for(int k=0;k<lj[j].fi.size();k++){
					c[i+k]=lj[j].se[k];
				}
				bool pd=true;
				for(int k=0;k<a.size();k++){
					if(c[i]!=b[i]){
						pd=false;
						break;
					}
				}
				if(pd)ans++;
			}
			c=a;
		}
		cout<<ans<<endl;
	}
	return 0;
}
