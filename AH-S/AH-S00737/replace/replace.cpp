#include<bits/stdc++.h>
using namespace std;
long long n,q;
string S1,S2,s1[200010],s2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>S1>>S2;
		long long ans=0;
		for(long long i=1;i<=n;i++){
			if(S1.find(s1[i])>=0&&S1.find(s1[i])<S1.size()){
				long long w=S1.find(s1[i]);
				string sf=S1;
				sf.erase(w,s1[i].size());
				sf.insert(w,s2[i]);
				if(sf==S2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return  0;
}
