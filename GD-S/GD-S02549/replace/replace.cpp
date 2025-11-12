#include <bits/stdc++.h>
using namespace std;
long long t,i,j,v,ans,k,n,q,b;
pair <string ,string> s[200005];
string p,r,o;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	for(i=1;i<=q;i++){
		cin>>p>>r;
		
		for(j=1;j<=n;j++){
			k=0;
			while(1){
				//cout<<"*";
				b=p.find(s[j].first,k);
				if(b<0) break;
				o=p;
				o.erase(b,s[j].first.size());
				o.insert(b,s[j].second);
				if(o==r) ans++;
				k=b+1;
			}
		} 
		cout<<ans<<endl;
		ans=0;
	}
	
	return 0;
} 
