#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],t1,t2,ans=0;
ll te;
bool flag=0;
void dfs(ll t,ll cnt,ll s){
	if(flag==0){
		return;
	}
	if(te>=INT_MAX){
		flag=0;
		return;
	}
	if(t>n){
		ans=max(ans,cnt);
		te++;
		return;
	}
	if(s==k){
		te++;
		dfs(t+1,cnt+1,a[t+1]);
	}else{
		te++;
		dfs(t+1,cnt,s^a[t+1]);
		dfs(t+1,cnt,a[t+1]);
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(k!=0&&a[i]==0){
			i--;
			n--;
		}else if(a[i]!=1){
			flag=1;
		}else{
			t2++;
		}
	}
	if(flag==0){
		if(k==1){
			cout<<t2;
			return 0;
		}else if(k==0){
			for(ll i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}else if(a[i]==0){
					ans++;
				}
			} 
		}
	}else{
		dfs(1,0,a[1]);
	}
	cout<<ans;
	return 0;
}
