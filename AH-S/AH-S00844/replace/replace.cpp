#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,q,ans;
struct node{
	string x,y;
}a[200005];
unordered_map<string,int> mp;
void dfs(string x,string y,int dep){
	if(x==y){ans++;return;}
	if(dep>n+1)return;
	for(int i=1;i<=n;i++){
		int l=0,r=0;
		string s;
		int f=0;
		while(l+a[i].x.size()-1<x.size()){
			r=l;f=0;
			for(int j=r;j<(r+a[i].x.length());j++){
				if(x[j]!=a[i].x[j]){
					f=1;
					break;
				}
			}
			if(!f){
				s+=a[i].y;
				for(int j=((int)r+(((a[i].x).size())));j<x.size();j++){
					s+=x[j];
				}
				break;
			}
		}
		if(!f)dfs(s,y,dep+1);
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	while(q--){
		string x,y;cin>>x>>y;
		dfs(x,y,0);
		cout<<ans<<endl;
	}
	return 0;
}
