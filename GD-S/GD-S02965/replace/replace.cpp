#include<bits/stdc++.h>
using namespace std;

int n,q;
string ss[200005][5];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ss[i][1]>>ss[i][2];
	}
	while(q--){
		long long ans=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			if(ss[i][1].size()>s1.size()) break;
			for(int j=0;j<=s1.size()-ss[i][1].size();j++){
				if(s1.substr(j,ss[i][1].size())==ss[i][1]) {
					//cout<<j<<endl;
					string sc="";
					for(int k=0;k<j;k++) sc+=s1[k];
					sc+=ss[i][2];
					for(int k=j+ss[i][1].size();k<s1.size();k++) sc+=s1[k];
					if(sc==s2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
