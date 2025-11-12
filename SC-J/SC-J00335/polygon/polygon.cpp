#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
long long a[5009],n,ans,vis[5009];
void dfs(long long x,long long sum,long long mx,long long len){
	//cout<<x<<" ";
	if(len>=3&&sum>mx*2){
		ans++;
		//cout<<endl;
	} 
	vis[x]++;
	for(int i=x+1;i<=n;i++){
		if(!vis[i]){
			dfs(i,sum+a[i],max(a[i],mx),len+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		dfs(i,a[i],a[i],1);
	}
	cout<<ans%998244353;
	return 0;
}