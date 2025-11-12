#include<bits/stdc++.h>
using namespace std;
int a[100005],vis[100005],x[100005];
int n,m;
const long long mod=998244353;
long long ans=0;
string s;
void dfs(int pos){
	if(pos==n+1){
		int num=0,kil=0;
		for(int i=1;i<=n;i++){
			if(x[i]<=kil||s[i]=='0'){
				kil++;
			}else{
				num++;
				if(num>=m){
					ans++;
					ans%=mod;
					return;
				}
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			x[pos]=a[i];
			dfs(pos+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;
	int flag=0,kl=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0'){
			flag=1;
			kl++;
		}
	}
	if(n-kl<m){
		cout<<0<<endl;
		return 0;
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	
	if(flag==0){
		int js=0;
		for(int i=1;i<=n;i++){
			if(a[i]>0)js++;
		}
		if(js<=m){
			cout<<0<<endl;
			return 0;
		}
		long long l=1;
		for(int i=2;i<=n;i++){
			l=l*i%mod;
		}
		cout<<l<<endl;
		return 0;
	}
	if(m==1){
		int js=0;
		int k=0;
		for(k=1;k<=n;k++){
			if(s[k]=='1')break;
		}
		k--;
		for(int i=1;i<=n;i++){
			if(a[i]>k){
				js++;
			}
		}
		long long ans1=js;
		for(int i=2;i<n;i++){
			ans1=ans1*i%mod;
		}
		cout<<ans1<<endl;
	}else{
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
