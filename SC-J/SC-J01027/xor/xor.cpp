#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500010];
bool A=1,B=1;
int ans=0,cnt=0;
void dfs(int id,int sum){
	if(id>n){
		return;
	}
	if(sum==k&&id!=0){
		cnt++;
		sum=0;
	}
	if(id==n){
		ans=max(ans,cnt);
		cnt=0;
		return;
	}
	for(int i=id+1;i<=n;i++){
		dfs(i,sum^a[i]);
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			A=0;
		}
		if(a[i]!=0&&a[i]!=1){
			B=0;
		}
	}
	if(A==1){
		cout<<n/2;
		return 0;
	}
	else if(B==1){
		if(k==0){
			a[n+1]=-1;
			int i=1;
			ans=0;
			while(i<=n){
				if(a[i]==0){
					ans++;
				}
				else if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
				i++;
			}
			cout<<ans;
			return 0;
		}
		else if(k==1){
			ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	else{
		ans=0;
		dfs(0,0);
		cout<<ans;
		return 0;
	}
	return 0;
}