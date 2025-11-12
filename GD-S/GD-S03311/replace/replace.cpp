#include <iostream>
#include <cstdio>
#define fi first
#define se second
using namespace std;
int n,q;
pair<string,string> p[200005]; 
int ans=0;
void sol(string s,string t){
//	cout<<s<<' '<<t<<endl;
	for(int l=0;l<s.size();l++){
		for(int r=l;r<s.size();r++){
//			cout<<l<<' '<<r<<endl; 
			string y="";
			for(int i=l;i<=r;i++)	
				y+=s[i];
			string x="",z="";
			for(int i=0;i<l;i++)
				x+=s[i];
			for(int i=r+1;i<s.size();i++)
				z+=s[i];
//			cout<<x<<' '<<y<<' '<<z<<endl; 
			for(int i=1;i<=n;i++){
				if(p[i].fi==y){
					string nw=x+p[i].se+z;
//					cout<<nw<<endl;
					if(nw==t)
						ans++; 
				}
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i].fi>>p[i].se;
	while(q--){
		string s,t;
		cin>>s>>t;
		sol(s,t);
		cout<<ans<<endl;
		ans=0; 
	} 
	return 0;
}

