#include<bits/stdc++.h>
#define ll long long
const int N=2e5+10;
using namespace std;
int n,q,ans[N];
string s1[N],s2[N],t1[N],t2[N];
signed main(){
	freopen("replace.in","r",stdin);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;++i) cin>>t1[i]>>t2[i];
	if(n<=10000||q==1){
		for(int i=1;i<=q;++i){
			for(int k=1;k<=n;++k){
				string t3=t1[i];
				for(int j=0;j<t3.size();++j){
					if(j+s1[k].size()>t3.size()) break;
					int cnt1=0,cnt2=0;
					bool f=1;
					for(int u=j;u<j+s1[k].size();++u){
						if(t3[u]!=s1[k][cnt1++]){
							f=0;
							break;
						}
					}
					if(f){
						for(int u=j;u<j+s1[k].size();++u)
							t3[u]=s2[k][cnt2++];
						if(t3==t2[i]) ans[i]++;
						break;
					}
				}
			}
		}
		for(int i=1;i<=q;++i) cout<<ans[i]<<"\n";
		freopen("replace.out","w",stdout);
		return 0;
	}
	freopen("replace.out","w",stdout);
	return 0;
}
