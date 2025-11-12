#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
bool stt;
const int N=2e5+10;
const ull p=131,q=29;
int n,m,sum=0;
ull hash_s[N];
unordered_map<ull,int> mp;
string s,t;
bool edd;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		int us=0;
		for(int i=0;i<s.size();i++){
			us=us*p+s[i]*q+t[i];
		}
		mp[us]++;
	}
	while(m--){
		cin>>s>>t;
		int ans=0;
		if(s.size()!=t.size()) {cout<<0<<"\n";continue;}
		int l=0,r=t.size()-1;
		for(int i=0;i<s.size();i++) if(s[i]!=t[i]) {l=i;break;}
		for(int i=s.size()-1;i>=0;i--) if(s[i]!=t[i]) {r=i;break;}
		for(int i=0;i<=l;i++){
			int us=0;
			for(int k=i;k<r;k++) us=us*p+s[k]*q+t[k];
			for(int j=r;j<=n;j++){
				us=us*p+s[j]*q+t[j];
				ans+=mp[us];
			}
		}
		cout<<ans<<"\n";
	}
	cerr<<(&edd-&stt)/1024.0/1024<<"\n";
	return 0;
}
