#include<bits/stdc++.h>
using namespace std;
using ll=int;
ll n,q,a;
string s[200005][3],s1,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=2;j++){
			cin>>s[i][j];
		}
	}while(q--){
		cin>>s1>>s2;
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll z=s[i][1].size();
			for(int j=0;j<=s1.size()-z+1;j++){
				ll f=1;
				for(ll k=j;k<j+z;k++){
					if(s[i][1][k]!=s1[k])f=0;
				}if(f){
					string s3=s1;
					for(ll k=j;k<j+z;k++){
						s3[k]=s[i][2][k];
					}if(s3==s2)ans++;
				}
			}
		}cout<<ans<<endl;
	}return 0;
}
