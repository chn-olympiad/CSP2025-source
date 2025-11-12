#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 100005
int n,q;
string s1[MAXN],s2[MAXN];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string x1,x2;cin>>x1>>x2;
		int pos=0,ans=0;
//		cout<<x2<<endl;
		while(pos<x1.length()-1){
			for(int j=1;j<=n;j++){
				if(x1.substr(pos,s1[j].length())==s1[j]){
					string tp="";
					tp+=x1.substr(0,pos);
					tp+=s2[j];int h=pos+s1[j].length();
					tp+=x1.substr(h,x1.length()-h);
//					cout<<x1<<' '<<s1[j]<<' '<<tp<<' '<<ans<<'\n';
					if(tp==x2) ans++;
				}
			}pos++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
