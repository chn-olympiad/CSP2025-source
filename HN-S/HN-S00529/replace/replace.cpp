#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string s1[200010],s2[200010],t1,t2,a1,b1,c1,a2,b2,c2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(ll i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		ll ans=0;
		for(ll x=0;x<t1.size();x++){
			for(ll z=x;z<t1.size();z++){
				a1=t1.substr(0,x),b1=t1.substr(x,z-x+1),c1=t1.substr(z+1,t1.size()-z-1);
				a2=t2.substr(0,x),b2=t2.substr(x,z-x+1),c2=t2.substr(z+1,t1.size()-z-1);
				if(a1==a2&&c1==c2)
					for(ll j=1;j<=n;j++)
						if(b1==s1[j]&&b2==s2[j])
							ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
