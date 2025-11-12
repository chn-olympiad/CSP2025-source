#include<bits\stdc++.h>
using namespace std;
// wei ren min fu wu
int mod_=998244353;
int c[505],flag[505],dp[505]; 
long long j[505];
int j_(int j__){
if(j[j__])return j[j__];
if(j__)return j__*j_(j__-1)%mod_;
return 1;}
int slove(int l,int l_[505],int r){
if(!l)return j_(l);
}
int main(){ 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,l;cin>>n>>m;
	l=n-m;
	string s;
	cin>>s;
	if(s[0]=='0')flag[0]=1;
	for(int i=1;i<s.size();i++){
	flag[i]=flag[i-1];
	if(s[i]=='0')flag[i]++;}
	if(flag[n-1]>l){cout<<0;return 0;}
	for(int i=0;i<n;i++)scanf("%d",c+i);
	sort(c,c+n);
	cout<<j_(n);
	return 0;
}
