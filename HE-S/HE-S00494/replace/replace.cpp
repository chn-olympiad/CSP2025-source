#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int n,q;

map<string,string> mp;
map<string,long long> cnt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
		cnt[s1]++;
	}
	while(q--){
		long long ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(auto it:mp){
			string s1=it.first;
			string s2=it.second;
			int i=t1.find(s1);
			if(t1.substr(0,i)+s2+t1.substr(i+s1.size(),t1.size()-(i+s1.size()))==t2) ans+=cnt[s1];
		}
		cout<<ans<<endl;
	}
}
