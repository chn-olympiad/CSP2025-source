#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>m;
int n,k,ans;
bool flagB=true,flagA=true;
int a[500010],b[500010];
int v(int l,int r){
	return b[l-1]^b[r];
}
int dfs(int l,int r){
	int fans=0;
	for(int i=r+1;i<=n;i++){
		if(m.count(make_pair(r+1,i))==0)m[make_pair(r+1,i)]=dfs(r+1,i);
		fans=max(fans,m[make_pair(r+1,i)]);
	}
	return fans+(v(l,r)==k);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flagA=false;
		if(a[i]!=0&&a[i]!=1)flagB=false;
		b[i]=b[i-1]^a[i];
	}
	if(flagA){
		cout<<n/2;
		return 0;
	}
	if(flagB){
		int f=0,t=0;
		for(int i=1;i<=n;i++){
			if(a[i])t++;
			else f++;
		}
		if(k)cout<<t;
		else{
			t=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					f+=t/2;
					t=0;
				}
				else t++;
			}
			cout<<f+t/2;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		//if(m.count(make_pair(1,i))==0)m[make_pair(1,i)]==dfs(1,i);
		ans=max(ans,dfs(1,i));
	}
	cout<<ans;
	return 0;
}
