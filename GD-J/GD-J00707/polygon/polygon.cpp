#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5010],ans,t[5050];
bool flag=1;
void DFS(int need,int x,int cnt){
	if(x>n+1) return;
	if(cnt==need){
		ll tmp=0,maxn=-1;
		for(int i=0;i<cnt;i++){
			tmp+=t[i];
			maxn=max(t[i],maxn);
		}
		if(maxn*2<tmp) ans=(ans+1)%998244353;
		return;
	}
	t[cnt]=a[x];
	DFS(need,x+1,cnt+1);
	t[cnt]=0;
	DFS(need,x+1,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag){
		for(int dis=2;dis<n;dis++){
			for(int i=1;i<=n-dis;i++){
				ans+=i*(n-i-dis+1)%998244353;
			}
		}
		cout<<ans%998244353;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=3;i<=n;i++){
		DFS(i,1,0);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
