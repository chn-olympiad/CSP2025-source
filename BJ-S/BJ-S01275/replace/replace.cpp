#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		long long ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int len=t1.size();
		for(int i=0;i<len;i++){
			string t;
			for(int j=1;j<=n;j++){
				t=t1.substr(0,i);
				if(t1.substr(i,s1[j].size())==s1[j]){
					t=t+s2[j];
					string k=t1.substr(t.size(),len-t.size());
					t=t+k;
					if(t==t2) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
