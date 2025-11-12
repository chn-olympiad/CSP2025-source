#include<bits/stdc++.h>
using namespace std;
using pii=pair<string,string>;
int n,q;
map<pii,int> st;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(n--){
		string a,b;
		cin>>a>>b;
		st[{a,b}]++;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int i=0;
		for(;i<a.size();i++){
			if(a[i]!=b[i]) break;
		}
		int j=a.size()-1;
		for(;j>=0;j--){
			if(a[j]!=b[j]) break;
		}
		int ans=0;
		for(int l=i;l>=0;l--){
			for(int r=j;r<a.size();r++){
				int len=r-l+1;
				string sa=a.substr(l,len),sb=b.substr(l,len);
				if(st.find({sa,sb})!=st.end()) ans+=st[{sa,sb}];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

