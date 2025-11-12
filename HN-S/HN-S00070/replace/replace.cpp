//#inpresation111 's Code
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define int long long
using  namespace std;
int n,q;
string s1[200001],s2[200001],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		
	}
	for(int i=1;i<=q;i++){
		int  ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			if((t1.find(s1[j])==t2.find(s2[j]))&&(t1.find(s1[j])!=18446744073709551615)){
				int l=t1.find(s1[j]);
				string w=t1.substr(0,l);
				string t=t1.substr(l+s1[j].size());
				string w0=t2.substr(0,l);
				string t0=t2.substr(l+s1[j].size());
				if(w==w0&&t==t0){
					ans++;
				}
//				cout<<t1.find(s1[j])<<" "<<t1.size()<<" "<<(t1.find(s1[j])<t1.size())<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;

}
//



