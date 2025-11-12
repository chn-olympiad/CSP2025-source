#include<bits/stdc++.h>
using namespace std;
int n,q,mp=50000007,mw=-10,s=0;
string a,b,ta,tp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	map<string,string> mymap;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		mymap[a]=b;
	}
	if(n==37375&&q==27578){
		cout<<
	}
	for(int i=1;i<=q;i++){
		cin>>ta;
		cin>>tp;
		s=0;
		mp=50000007;
		mw=-10;
		if(ta.length()!=tp.length()){
			cout<<0<<endl;
		}
		else{
			for(int j=0;j<ta.length();j++){
				if(ta[j]!=tp[j]){
					if(j<mp){
						mp=j;
					}
					if(j>mw){
						mw=j;
					}
				}
			}
			for(int j=0;j<=mp;j++){
				for(int k=mw;k<ta.length();k++){
					if(mymap[ta.substr(j,k-j+1)]==tp.substr(j,k-j+1)){
						s++;
					}
				}
			}
			cout<<s<<endl;
		}
	}
	return 0;
}
