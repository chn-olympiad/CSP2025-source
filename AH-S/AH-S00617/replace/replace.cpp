#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		string a,b;
		int ans=0;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			for(int j=0;j<a.size()-s1[i].size()+1;j++){
				if(a.substr(j,s1[i].size())==s1[i]&&(a.substr(0,j)+s2[i]+a.substr(j+s1[i].size(),a.size()-j-s1[i].size()+1))==b)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
