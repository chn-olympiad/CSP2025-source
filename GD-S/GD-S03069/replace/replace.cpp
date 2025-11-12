#include<bits/stdc++.h>
using namespace std;
int n,q;
int const D=2e5+50;
map<string,string>s;
string p[D];
string p1[D];
string a,b;
long long ans=0;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	iostream::sync_with_stdio(false);
	cout.tie();cin.tie();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		s[a]=b;
		p[i]=a;
		p1[i]=b;
	}
	while(q--){
		cin>>a>>b;
		ans=0;
//		if(a.size()<=2000){//±©Á¦ 
//			for(int i=0;i<a.size();i++){
//				for(int j=i+1;j<a.size();j++){
//					string kl=a.substr(i,j-i+1);
//					if(s.count(kl)!=0){
//						string aa=a;
//						aa.replace(i,kl.size(),s[kl]);
//						if(aa==b)ans++;
//					}
//				}
//			}
//			cout<<ans<<endl;
//			continue;
//		}
		for(int i=1;i<=n;i++){
			if(a.find(p[i])!=string::npos){
				string aa=a;
				aa.replace(a.find(p[i]),p[i].size(),p1[i]);
				if(aa==b)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
