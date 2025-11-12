#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,ans;
string a,b,t1,t2,di1,di2;
unordered_map<string,string> s;
bool flag1,flag2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(n--){
		cin>>a>>b;
		s[a]=b;
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		ans=0;
		flag1=1;
		for(l=0;flag1 && l<t1.size();l++){
			flag2=1;
			if(t1[l]!=t2[l]) flag1=0;
			for(r=t1.size()-1;flag2 && r>=l;r--){
				di1=t1.substr(l,r-l+1);
				di2=t2.substr(l,r-l+1);
				if(s[di1]==di2) ans++;
				if(t1[r]!=t2[r]) flag2=0;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
