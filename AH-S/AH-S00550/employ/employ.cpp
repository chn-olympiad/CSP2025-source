#include<bits/stdc++.h>
using namespace std;

int n,m,per[505],a[505],sum,unsum;string s;bool b[505],flag;long long ans;
void dfs(int t){
	if(t==n+1){
		for(int i=1;i<=n;i++){
			if(s[i-1]==49 && unsum<per[a[i]]){
				sum++;
				if(sum>=m){
					ans++;break;
				}
			}
			else unsum++;
		}
		sum=unsum=0;
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			a[t]=i;
			b[i]=1;
			dfs(t+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++){
		cin >> per[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]==48){
			flag=1;
			break;
		}
	}
	if(flag)dfs(1);
	else{
		ans=1;
		for(int i=n;i>=1;i--){
			ans=ans*i%998244353;
		}
	}
	cout << ans;
	return 0;
}
