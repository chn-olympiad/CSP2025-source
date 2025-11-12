#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		long long ans=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=0;i<n;i++){
			string a=s1.substr(0,s[i][0].size());
			string b=s2.substr(0,s[i][1].size());
			if(a==s[i][0]&&b==s[i][1]){
				if(s[i][0].size()==s1.size()){
//					cout<<s[i][0]<<' '<<s[i][1]<<endl;
					ans++;
					continue;
				}
				string c=s1.substr(s[i][0].size());
				string d=s2.substr(s[i][0].size());
				if(c==d){
//					cout<<s[i][0]<<' '<<s[i][1]<<endl;
					ans++;
				}
			}
		}
		int l=0;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				l=i;
				break;
			}
		}
		string p=s1.substr(0,l);
		for(int i=0;i<n;i++){
			if(l+s[i][0].size()>s1.size()){
				continue;
			}
			string a=s1.substr(l,s[i][0].size());
			string b=s2.substr(l,s[i][1].size());
//			cout<<a<<' '<<b<<endl;
			if(a==s[i][0]&&b==s[i][1]){
				string c=s1.substr(l+s[i][0].size());
				string d=s2.substr(l+s[i][0].size());
				if(c==d){
//					cout<<s[i][0]<<' '<<s[i][1]<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
