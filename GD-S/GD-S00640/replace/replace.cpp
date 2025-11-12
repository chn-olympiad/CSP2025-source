#include<iostream>
#include<cstring>
using namespace std;
const int N=2e5+5;
const int L=1e6+5;
int n,q;
string s[2][N],t1,t2;
int ans;
int nxt[L];
int find(string s1,string s2){
	for(unsigned int i=0,j;i<s1.size();i++){
		for(j=0;j<s2.size()&&s1[i+j]==s2[j];j++)
		if(j==s2.size()-1) return i;
		i+=j;
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[0][i]>>s[1][i];
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			unsigned int len=s[0][i].size();
			if(len>t1.size()) continue;
			int p=find(t1,s[0][i]),q=find(t2,s[1][i]);
			if(p==-1||q==-1) continue;
//			cout<<s[0][i]<<" "<<s[1][i]<<"\n";
//			cout<<p<<" "<<q<<"\n";
//			cout<<t1.substr(p+len)<<" "<<t2.substr(p+len)<<"\n";
//			cout<<t1.substr(0,p)<<" "<<t2.substr(0,p)<<"\n";
			if(p!=q) continue;
//			cout<<"YES\n";
			if(t1.substr(p+len)!=t2.substr(p+len)) continue;
//			cout<<"YES\n";
			if(t1.substr(0,p)!=t2.substr(0,p)) continue;
//			cout<<"YES\n";
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
