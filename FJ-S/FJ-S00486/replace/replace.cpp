#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1_90[N],s2_90[N];
string th(string s_90,int k_90) {
	int m_90=s1_90[k_90].size();
	string str_90="";
	int long_90=s_90.size();
	bool flag;
	for(int i=0; i<long_90-m_90; i+=m_90) {
		flag=true;
		for(int j=i; j<=m_90; j++) {
			if(s_90[j]!=s1_90[k_90][j-i]) {
				flag=false;
				break;
			}
		}
		if(flag) {
			for(int j=0; j<i; j++) {
				str_90+=s_90[j];
			}
			str_90+=s2_90[k_90];
			for(int j=i+m_90;j<long_90;j++){
				str_90+=s_90[j];
			}
			return str_90;
		}
	}
	for(int i=1; i<long_90-m_90; i+=m_90) {
		flag=true;
		for(int j=i; j<=m_90; j++) {
			if(s_90[j]!=s1_90[k_90][j-i]) {
				flag=false;
				break;
			}
		}
		if(flag) {
			for(int j=0; j<i; j++) {
				str_90+=s_90[j];
			}
			str_90+=s2_90[k_90];
			for(int j=i+m_90;j<long_90;j++){
				str_90+=s_90[j];
			}
			return str_90;
		}
	}
	if(s1_90[k_90]==s_90) return s2_90[k_90];
	return s_90;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s1_90[i]>>s2_90[i];
	}
	for(int i=1; i<=q; i++) {
		string t1_90,t2_90;
		int ans=0;
		cin>>t1_90>>t2_90;
		for(int j=1; j<=n; j++) {
			if(th(t1_90,j)==t2_90) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
