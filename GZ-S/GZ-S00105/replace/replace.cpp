//GZ-S00105 贵阳市第三中学 周忠杰  
#include<bits/stdc++.h>
using namespace std;
//Ren5Jie4Di4Ling5%
#define ll long long
string a[200005][3];
string b[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,q;
	cin>>n>>q;
	bool flag=1;
	for(ll i=1;i<=q;i++){
		cin>>a[i][1]>>a[i][2];
		for(ll j=1;j<a[i][1].size();j++){
			if((a[i][1][j]!='a'&&a[i][1][j]!='b')||(a[i][2][j]!='a'&&a[i][2][j]!='b'))
			{
				flag=0;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		cin>>b[i][1]>>b[i][2];
	}
	if(flag==1){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=0;j<b[i][1].size();j++){
				if((b[i][1][j]=='b'&&b[i][2][j]=='a')||(b[i][1][j]=='a'&&b[i][2][j]=='b')){
					ans++;
				}
			}
		}
		for(ll i=1;i<=q;i++){
			cout<<ans<<endl;
		}
	}
	else{
		for(ll i=1;i<=q;i++){
			cout<<0<<endl;
		}
	}
}
