#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e5+10;
ll n,q;
string s[N][10],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}while(q--){
		ll ans=0;
		cin>>t1>>t2;
		for(ll j=1;j<=n;j++){
			for(ll i=0;i<t1.size()-s[j][1].size()+1;i++){
				if(t1.substr(i,s[j][1].size())==s[j][1]){
					string tmp=t1.substr(0,i)+s[j][2]+t1.substr(i+s[j][1].size());
				
					if(tmp==t2){
						ans++;
	
					}
						
				}
			}
		}printf("%lld\n",ans);
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

