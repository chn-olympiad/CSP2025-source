#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int a[501];
int ans;
int id[501];
const int mod=998244353;
bool check(){
	int sum=0;
	int now=0;//give up
	for(int i=1;i<=n;i++){
		if(now>=a[id[i]]){
			now++;
			continue;
		}
		if(s[i-1]=='1'){
			sum++;
		}else{
			now++;
		}
	}
	return sum>=m;
}
int jc(){
	int pos=0,rec=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'){
			pos=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]>=pos){
			rec++;
		}
	}
	int kp=1;
	for(int j=1;j<=n-1;j++)kp=kp%mod*j%mod;//rec-1 
	return rec%mod*kp%mod;
}
int yp(){
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0')return 0;
	}
	return 1;
}
int kk(){
	int sump=1;
	int yes=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0)continue;
		else yes++;
	}
	if(yes<n)return 0;
	for(int i=1;i<=yes;i++){
		sump=sump*i%mod;
	}
	return sump;
}
signed main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i],id[i]=i;
//	if(yp()){
//		cout<<kk();
//		return 0;
//	}
	if(m==1&&n>10){
	   cout<<jc();
	   return 0;
	}
	do{
		ans+=check();
		if(ans>=mod){
			ans-=mod;
		}
		
	}while(next_permutation(id+1,id+1+n));
	cout<<ans;
	return 0;
}
