#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=2e5+20;
ll n,m,ans;
string s1[N],s2[N];

void dfs(string x,string y,ll p){
	if(x==y){
		ans++;
		return;
	}
	for(ll i=p+1;i<=n;i++){
		ll p=x.find(s1[i]);
		while(p!=-1){
			ll l=p,r=l+s1[i].size();
			p=x.find(s1[i],p+s1[i].size());
			string ss=x;
			for(ll j=l;j<r;j++)ss[j]=s2[i][j-l];
			dfs(ss,y,i);
		}
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	
	while(m--){
		string x,y;ans=0;
		cin>>x>>y;
		if(x.size()!=y.size()){cout<<0<<endl;continue;}
		dfs(x,y,0);
		cout<<ans<<endl;
	}
	
	return 0;
} 
