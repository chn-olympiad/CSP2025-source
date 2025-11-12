#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string s[200005][2];
int ans=0;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		ans=0;
		string a,b;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			int p=0;
			while((int)(a.find(s[i][0],p))!=-1){
				int t=(int)(a.find(s[i][0],p));
				string h1="",h2="";
				if(t!=0){
					h1=a.substr(0,t);
				}
				if(t!=a.size()-1){
					h2=a.substr(t+s[i][0].size(),a.size()-t-s[i][0].size());
				}
				string pp=h1+s[i][1]+h2;
				if(pp==b) ans++;
				p=t+s[i][0].size();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
