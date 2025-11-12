#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int mod=998244353;
void init(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
int n,m;
string nd;
int nx[501];
void te(){
	int li=0;
	for(int i=1;i<=n;i++){
		li+=(!nx[i]);
	}
	n-=li;
	int jc1=1;
	for(int i=n-m+1;i<=n;i++){
		jc1=(jc1*i)%mod;
	}
	cout<<jc1%mod;
	exit(0);
}
signed main(){
	init();
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>nd;
	for(int i=1;i<=n;i++){
		cin>>nx[i];
	}
	bool p=1;
	int pp=0;
	nd=" "+nd;
	for(int i=1;i<nd.size();i++){
		if(nd[i]=='0'){
			p=0;
			break;
		}
		else{
			pp++;
		}
	}
	if(pp<m){
		cout<<0;
		return 0;
	}
	if(p){
		te();
	}
	if(n==m){
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
