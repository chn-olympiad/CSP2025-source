#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2*1e5+5;
int n,k,ans;
int a[maxn]={};
bool vis[maxn]={};
void find(int x){
	int sum=a[x],i=x;
	if(a[x]==k){
		ans++;
		vis[x]=1;
		return;
	}
	else if(a[x]==0)return;
	while(1){
		i++;
		if(a[i]==0)return;
		sum+=a[i]+1;
		if(sum==k){
			ans++;
			for(;i>=x;i--)vis[i]=1;
			return;
		}
		if(sum>k||i>n)return;
	}
}

signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)if(!vis[i])find(i); 
	cout<<ans;
	return 0;
} 
