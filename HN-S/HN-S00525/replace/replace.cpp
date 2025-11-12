#include<bits/stdc++.h>
using namespace std;
int n,q,ln,len[200010];
string s1[200010],s2[200010],t1,t2;
long long ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
	}
	while(q--){
		cin>>t1>>t2;
		ln=t1.size();
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=len[i]-1;j<ln;j++){
				if(t1.substr(j-len[i]+1,len[i])==s1[i]&&t1.substr(0,j-len[i]+1)+s2[i]+t1.substr(j+1)==t2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
