#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans,l,r,tot[200100];
string s[200100],s2[200100];
string q,q2,k,k2;

void abc(ll x,ll y){
	string k="";
	string k2="";
	for(ll i=x;i<=y;i++){
		k+=q[i];
		k2+=q2[i];
	}
	for(ll i=1;i<=n;i++){
		if(k==s[i] && k2==s2[i]) ans++;
	}
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	getchar();
	for(ll i=1;i<=n;i++){
		cin>>s[i]>>s2[i];
		tot[s[i].size()]++;
	}
	while(m--){
		ans=0,l=0,r=0;
		cin>>q>>q2;
		for(ll i=0;i<q.size();i++){
			if(q[i]!=q2[i]){
				l=i;
				while(q[i]!=q2[i]){
					i++;
				}
				r=i-1;
				
			}
		}
		for(ll i=0;i<q.size();i++){
			if(i>l) break;
			for(ll j=r;j<=q.size();j++){
				if(i<=l && j>=r && tot[j-i+1]!=0){
					abc(i,j);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
