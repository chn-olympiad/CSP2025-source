#include<bits/stdc++.h>
using namespace std;
const int mmod=998244353;
int n,m;string s;int c[505];long long cnt=1;
bool vis[505],k,l;int nut=0,nit=0;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0')vis[i+1]=false;
		else vis[i+1]=true;
		if(s[i]=='0'){
			k=true;
			nut++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			l=true;	
			nit++;
		}
	}
	nit=max(nit,nut);
	for(int i=2;i<=n;i++){
		cnt*=i;
		cnt%=mmod;
	}
	if(n==m&&(k==true||l==true)){
		cout<<"0";
		return 0;
	}
	if(n-nit<m){
		cout<<"0";
		return 0;
	}
	cout<<cnt;
	return 0;
}
