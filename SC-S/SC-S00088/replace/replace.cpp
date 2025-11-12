#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ans;string s1[200010],s2[200010],t1,t2;
map<int,bool>mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		mp[s1[i].size()]=1;
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++){
			for(int j=i;j<t1.size();j++){
				if(mp[j-i+1]==0)continue;
				cout<<i<<' '<<j<<'\n';
				for(int s=1;s<=n;s++){
				if(s1[s].size()!=j-i+1)continue;
				int f=1;
				for(int k=i,l=0;k<=j;k++,l++){
					cout<<s1[s][l]<<' '<<t1[k]<<'\n';
					if(s1[s][l]!=t1[k]||s2[s][l]!=t2[k]){
						f=0;break;
					}
				}
				if(f==1)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
