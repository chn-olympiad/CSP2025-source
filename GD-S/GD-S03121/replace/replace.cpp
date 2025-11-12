#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string c[2005],r[2005],s1,s2;
string chan(string s1,int tp,string s2){
	string s=s1;
	for(int i=tp;i<tp+s2.length()-1;i++){
		s[i]=s2[i];
	}
	return s;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>c[i]>>r[i];
	while(q--){
		ans=0;
		cin>>s1>>s2;
		for(int i=0;i<n;i++){
			if((s1.find(c[i]))==-1) continue;
			string s=chan(s1,s1.find(c[i]),r[i]);
			cout<<s<<endl; 
			if(s==s2) ans++;
		} 
		
		cout<<ans<<endl;
	}
	return 0;
} 
