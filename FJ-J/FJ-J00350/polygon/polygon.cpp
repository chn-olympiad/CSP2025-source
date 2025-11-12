#include<bits/stdc++.h> 
#define mod 998244353
using namespace std;
int n,a[100010];
long long ans;
bool cmp(int x,int y){return x>y;}
void dfs(int ch,int len,int len_max,int m){
	len+=a[ch];
	if(len>len_max*2){
		if(m>=3){
			ans++; 
			ans%=mod;
		}
	}
	for(int i=ch+1;i<n;i++){
		dfs(i,len,len_max,m+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n,cmp); 
	for(int k=0;k<n;k++){
		dfs(k,0,a[k],1); 
	} 
	cout<<ans%mod;
} 
