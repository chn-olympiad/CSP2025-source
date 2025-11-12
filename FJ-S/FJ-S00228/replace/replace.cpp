#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef unsigned long long ull;
const int N=2e5+5;
const int M=5e6+5;
const ull base=131;
int n,T;
string S[N][2];
ull bs[M];
ull hs1,hs2,ht1[M],ht2[M];
void init(int n){
	bs[0]=1;
	for(int i=1;i<=n;i++) bs[i]=bs[i-1]*base;
}
void calc_hsh1(int j,int n){
	hs1=hs2=0;
	for(int i=1;i<=n;i++){
		hs1=hs1*base+(S[j][0][i]-'a');
		hs2=hs2*base+(S[j][1][i]-'a');
	}
}
void calc_hsh2(string t1,string t2,int n){
	ht1[0]=ht2[0]=0;
	for(int i=1;i<=n;i++){
		ht1[i]=ht1[i-1]*base+(t1[i]-'a');
		ht2[i]=ht2[i-1]*base+(t2[i]-'a');
	}
}
ull hsh(int l,int r,ull h[]){
	return h[r]-h[l-1]*bs[r-l+1];
}
int work(int j,int m){
	int n=S[j][0].size()-1;
	calc_hsh1(j,n);
	int ans=0;
	for(int i=1;i+n-1<=m;i++){
		if(hsh(i,i+n-1,ht1)==hs1){
			if(ht1[m]+(hs2-hs1)*bs[m-n-i+1]==ht2[m]) ans++;
		}
	}
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s1=" "+s1;
		s2=" "+s2;
		S[i][0]=s1,S[i][1]=s2;
	}
	init(5e6);
	while(T--){
		string s1,s2;
		cin>>s1>>s2;
		int m=s1.size();
		s1=" "+s1;
		s2=" "+s2;
		calc_hsh2(s1,s2,m);
		int ans=0;
		for(int i=1;i<=n;i++) ans+=work(i,m);
		cout<<ans<<'\n';
	}
	return 0;
}
