#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string a1[200005],a2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
	}
	while(q--){
		ll ans=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			if(s1.size()<a1[i].size()) continue;
			else if(s1.size()==a1[i].size()){
				if(s1==a1[i] && s2==a2[i]) ans++;
			}
			else{
				string x="";
				for(int j=0;j<s1.size()-a1[i].size();j++){
					if(j>=1)x=x+s1[j-1];
					string y="",z="";
					for(int k=j;k<j+a1[i].size();k++){
						y=y+s1[k];
					}
					if(y!=a1[i]) continue;
					for(int k=j+a1[i].size();k<s1.size();k++){
						z=z+s1[k];
					}
				//	cout<<x+a2[i]+z<<endl;
					if(y==a1[i]){
						if(x+a2[i]+z==s2) ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
