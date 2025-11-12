#include<bits/stdc++.h>
using namespace std;
map<string,string> ma;
int n,q,f,ans,m,cnt[1000005],f1;
string s[1000005],t,a,b,w;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t;
		cnt[i]=s[i].size();
		ma[s[i]]=t;
	}
	while(q--){
		cin>>a>>b;
		m=a.size();
		ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[i]>=m){
				if(s[i]==a&&ma[s[i]]==b) ans++;
				continue;
			}
			for(int j=0;j<m-cnt[i];j++){
				f1=1;
				for(int k=j;k<j+cnt[i];k++) if(s[i][k-j]!=a[k]){
					f1=0;
					break;
				}
				if(f1){
					t=a;
					w=ma[s[i]];
					for(int k=j;k<j+cnt[i];k++) a[k]=w[k-j];
					if(a==b){
						ans++;
						break;
					}
					a=t;
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}
