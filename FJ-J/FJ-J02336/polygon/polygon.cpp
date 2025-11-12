#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int b[1000005];
int hs;
int mod=998244353;
int dfs(int max,int gs,int wz,int zh){
	//cout<<wz<<":";
	if(wz==2){
		return zh;
	}
	if(gs==wz){
		return dfs(b[wz-1],1,wz-1,zh);
	}
	int zs=0;
	for(int i=1;i<=gs;i++){
		zs+=b[wz-i];
	}
	
	int g=0;
	if(wz==gs+1&&wz!=3){
		if(zs>max){
		g++;	
		}
	}
	int cs=max-zs;
	for(int i=1;i<=wz-gs-1;i++){
		if(b[i]>cs){
			g+=wz-gs-i;
			//cout<<g<<" ";
			break;
		}
	}
//	cout<<"  ";
	return  dfs(max,gs+1,wz,(zh+g)%mod);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+1+n);
	int da=dfs(b[n],1,n,0)%mod;
	cout<<da;
	return ;
}
signed main(){
	freopen("polygon.in ","r",stdin);
	freopen("polygon","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
} 
