#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,m;
struct rep{string x,y;}t[N];
map<string,ll>M;
//=========================================================
ll val(string x,string y){
	if(x.size()!=y.size()) return 0ll;
	ll l=0,r=x.size(),ans=0;
	for(;l<r;l++) if(x[l]!=y[l]) break;
	for(;r>0;r--) if(x[r]!=y[r]) break;
	string now="",to="";
	for(int i=l;i<r;i++) now+=x[i],to+=y[i];
	for(int i=l;i>=0;i--){
		string dt=now,yt=to;
		for(int j=r,tot=x.size();j<tot;j++){
			dt+=x[j]; yt+=y[j];
			ans+=M[dt+','+yt];
		}if(i>0) now=x[i-1]+now,to=y[i-1]+to; 
	}return ans;
}
//=========================================================
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		M[x+','+y]++;
	}
	for(int i=1;i<=m;i++){
		string x,y;
		cin>>x>>y;
		cout<<val(x,y)<<'\n';
	}
	return 0;
} 
