#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],l,vis[1005],k;
long long ans;
string s;
void fin(int h,int p,int fo){
	if(p>m)return ;
	if(m-p>n-h)return ;
	if(h==n && p==m){
		ans++;
		ans%=998244353;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(fo>=a[i])fin(h+1,p,fo);
			else if(s[h]=='0')fin(h+1,p,fo+1);
			else fin(h+1,p+1,fo);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n>10){
		cout<<0;
		return 0;
	}
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fin(0,0,0);
	cout<<ans<<" "; 
	return 0;
}
