#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200001][3];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			string f=t1;
			while(f.find(s[i][1])!=-1){
				int wz=f.find(s[i][1]);
				if((t1.substr(0,wz)+s[i][2]+t1.substr(wz+s[i][1].size(),t1.size()-1))==t2) ans++;
				f.erase(wz,s[i][1].size());
			}
		}
		cout<<ans<<endl;
	}
}
