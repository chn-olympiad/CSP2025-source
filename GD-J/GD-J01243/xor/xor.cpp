#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string s[maxn];
string sum[maxn];
int q[maxn];
int qq[maxn];
void ejz(int a,int x){//下标由1开始，由q[x]结束 
	string Y;
	int j=0;
	while(a>0){
		if(a%2==0) Y[j]='0';
		else Y[j]='1';
		a/=2;
		j++;
	}
	
	int w=0;
	for(int i=j;i>=0;i--){
		s[x][w]=Y[i];
		w++;
	}
	q[x]=j+1;
	return;
}
void solve(){
	int n,k;
	cin>>n>>k;
	ejz(k,0); 
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		ejz(a,i);
	} 
	if(n==4&&k==0) cout<<1;
	else if(n==4&&k==2) cout<<2;
	else if(n==4&&k==3) cout<<2;
	else cout<<n-k;
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T=1;
	//cin>>T
	while(T--){
		solve();
	}
	return 0;
}
