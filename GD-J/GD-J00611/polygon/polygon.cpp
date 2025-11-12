#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
const ll Mod=998244353;
int n,ans=0;
vector<ll> a(N);
void DFS(ll now,ll sum,ll mx,ll cnt){
	if(now>n){
		if(sum>2*mx&&cnt>=3){
			ans++;
			ans%=Mod;
		} 
		return ;
	}
	DFS(now+1,sum,mx,cnt);
	DFS(now+1,sum+a[now],max(mx,a[now]),cnt+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	DFS(1,0,0,0);
	cout<<ans%Mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
