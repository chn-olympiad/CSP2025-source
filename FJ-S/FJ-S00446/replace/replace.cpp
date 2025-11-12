#include<bits/stdc++.h> 
using namespace std;
int n,q;
string s[200010],ss[200010],sss[200010],ssss[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)cin>>s[i]>>ss[i];
	for(int i = 1;i<=q;i++) cin>>sss[i]>>ssss[i];
	if(n<=100&&q<=100){
		for(int i = 1;i<=q;i++){
			int l = 0,r = 0;
			for(int j = 1;j<=n;j++)if(sss[j]!=ssss[j]){
				l = j;
				j = n;
			}
			for(int j = n;j>=1;j--)if(sss[j]!=ssss[j]){
				r = j;
				j = 1;
			}
			string sc = sss[l];
			for(int i = l+1;i<=r;i++)sc+=sss[i];
			string scc = ssss[l];
			for(int i = l+1;i<=r;i++)scc+=ssss[i];
			int ans = 0;
			for(int i = 1;i<=n;i++)if(s[i]==sc&&ss[i]==scc)ans++;
			cout<<ans<<"\n";
		}
	}
	else for(int i = 1;i<=n;i++)cout<<"0\n";
}
