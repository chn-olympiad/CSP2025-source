#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5; 
int n,q,ans;
string t1[N],t2[N],s1,s2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>t1[i]>>t2[i];
	while(q--){
		ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int flg=0,c=0;
			for(int j=0;j<s1.size();j++){
				flg=0;
				if(s1[j]==s2[j]) flg=1;
				int k=0;
				while(s1[j+k]==t1[i][k]&&s2[j+k]==t2[i][k]&&k<t1[i].size())
					k++;
				if(k==t1[i].size()){
					while(s1[j+k]==s2[j+k]&&k+j<s1.size()) k++;
					if(j+k==s1.size()) flg=1,ans++;
				}
				if(flg==0) break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
