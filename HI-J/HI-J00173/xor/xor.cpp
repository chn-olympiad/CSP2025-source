#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,k,ans=0,q=0,num;
void dfs(int x,int p,int cnt){
	if(x==k){
		cnt++;
		if(p==n){
			ans=max(cnt,ans);
			return;	
		}
		for(int i=p+1;i<=n;i++){
			dfs(a[i],i,cnt);
		}
		return;
	}
	if(p==n){
		ans=max(cnt,ans);
		return;	
	}
	
	for(int i=p+1;i<=n;i++){
		dfs(x^a[i],i,cnt);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	// ^ Òì»òºÍ 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			i--;
			n--;
			continue;
		}
		if(a[i]!=1){
			q=1;
		}
	}
	num=n;
	if(q==0){
		if(k==0){
			cout<<n/2;
		}else if(k==1){
			cout<<n;
		}else{
			cout<<0;
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			dfs(a[i],i,0);
		}
		cout<<ans;
		return 0;
	}
} 
