#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
map<string,string> mp;
string x,y;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string s1,s2;
	while(n--){
		cin>>s1>>s2;
		mp[s1]=s2;
		mp[s2]=s1;
	}
	while(q--){
		ll ans=0;
		cin>>x>>y;
		if(mp[x]==y) ans++;
		for(ll i=1;i<x.size();i++){
			for(ll j=i+1;j<x.size();j++){
				string t1=x.substr(0,i);
				string t2=x.substr(i,j-i);
				string t3=x.substr(j,x.size()-j+1);
				//cout<<t1<<" "<<t2<<" "<<t3<<"\n";
				//if(t1=="xa" && t2=="bc" && t3=="x") cout<<"---"<<t1<<mp[t2]<<mp[t3]<<"---";
				if(t1+t2+t3==y) ans++;
				else if(mp[t1]+t2+t3==y) ans++;
				else if(t1+mp[t2]+t3==y) ans++;
				else if(t1+t2+mp[t3]==y) ans++;
				else if(mp[t1]+mp[t2]+t3==y) ans++;
				else if(t1+mp[t2]+mp[t3]==y) ans++;
				else if(mp[t1]+t2+mp[t3]==y) ans++;
				else if(mp[t1]+mp[t2]+mp[t3]==y) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
