#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N],t[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>s[i]>>t[i];
	while(q--){
		string a,b;
		int ans=0;
		cin>>a>>b;
		for(int i=0;i<n;i++){
			int pos=0;
			while(a.find(s[i],pos)!=string::npos){
				string c=a.substr(0,a.find(s[i],pos))+t[i]+a.substr(a.find(s[i],pos)+s[i].size(),a.size()-a.find(s[i],pos)-s[i].size());
				if(c==b)ans++;
				pos=a.find(s[i],pos);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
