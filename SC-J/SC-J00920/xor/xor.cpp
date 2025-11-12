#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+5;
int n,k;
int a[maxn],xxor[maxn];
int cnt=0,cnt1=0;
bool vis[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xxor[i]=a[i];
		if(a[i]==1) cnt++;
		else if(a[i]==0) cnt1++;
	}
	if(cnt==n&&k==0){
		cout<<n/2;
		return 0;
	}
	else if(cnt+cnt1==n){
		int ans=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
				else if(a[i]==0) continue;
			}
			cout<<ans;
			return 0;
		}
		else if(k==0){
			bool flag=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					if(flag==1){
						ans++;
						flag=0;
					}
					else if(flag==0) flag=1;
				}
				else if(a[i]==0) continue;
			}
			cout<<ans;
			return 0;
		}
	}
	else{
		int ans=0;
		xxor[0]=0;
		for(int i=1;i<=n;i++){
			if(xxor[i]==k){
				ans++;
				vis[i]=1;
			}
			if((!vis[i-1])&&((xxor[i] xor xxor[i-1])==k)) {
				ans++;
				vis[i]=1;
			}
			else xxor[i]=xxor[i] xor xxor[i-1];
		}
		cout<<ans;
	}
	return 0;
}