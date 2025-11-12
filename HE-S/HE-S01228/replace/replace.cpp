#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const ll N=3e5+100,M=1e5+100,INF=0x3f3f3f3f3f3f3f3f;
int n,m,t,k;
ll ans=0;
string s1,s2;
string a[N],b[N];
string h[N],g[N];
unordered_map<int,int> mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(t<=100&&n<=100){
	while(t--){
		cin>>s1>>s2;
		ans=0;
		for(int i=1;i<=n;i++){
			int k=-1;
			int le=a[i].size();
			while(s1.find(a[i],k+1)!=-1){
				k=s1.find(a[i],k+1);
				string h="",o="";
				h=s1.substr(0,k)+b[i]+s1.substr(k+le);
				if(h==s2)ans++;
			}
		}
		cout<<ans<<"\n";
	}	
	}
	else{
	for(int i=1;i<=t;i++)cin>>h[i]>>g[i];
	if(t==1){
		bool fg=1;
		for(int i=0;h[1][i];i++){
			if(h[1][i]!='a'&&h[1][i]!='b')fg=0;
			if(g[1][i]!='a'&&g[1][i]!='b')fg=0;
		}
		if(fg==0){
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		int p=a[i].find("b"),q=b[i].find("b");
		mp[p-q]++;
	}
	for(int i=1;i<=t;i++){
		int p=h[i].find("b"),q=g[i].find("b");
		cout<<mp[p-q]<<"\n";
	}
	}
	
	return 0;
}
