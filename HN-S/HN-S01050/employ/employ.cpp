#include<bits/stdc++.h>
//#define int long long
#define mod(x) x%=998244353;
using namespace std;
int n,m,a[505],sum[505],cnt;
bool vis[505];
string s;
void dfs(int x,int shi,int ch){
	if(x>m){
		if(ch>=n){
			cnt++;
			mod(cnt);
		}
		return ;
	}
	if(m-shi<n) return ;
	for(int i=1;i<=m;i++){
		if(!vis[i]){
			vis[i]=1;
			if(a[i]>shi&&s[x-1]=='1'){
				dfs(x+1,shi,ch+1);
			}
			else{
				dfs(x+1,shi+1,ch);
			}
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//
	cin>>m>>n;
	cin>>s;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	dfs(1,0,0);
	cout<<cnt;
	return 0;
}
/*
 11
|10
=11
 11
&10
=10
 11
 10
 01
*/
