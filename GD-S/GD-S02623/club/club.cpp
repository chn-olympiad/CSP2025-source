#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll t,n;
ll a[N][4];
ll num[4];
ll now[N];
ll maxn;

ll check(){
	ll sum=0; 
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++){
		sum+=a[i][now[i]];
		num[now[i]]++;
		if(num[now[i]]>n/2) return -1;
	}
	return sum;
}
void dfs(ll dep){
	if(dep==n+1){
		ll sum=check();
		maxn=max(maxn,sum);
		return;
	}
	now[dep]=1;
	dfs(dep+1);
	now[dep]=2;
	dfs(dep+1);
	now[dep]=3;
	dfs(dep+1);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) {
			ll a1,a2,a3;
			cin>>a1>>a2>>a3;
			a[i][1]=a1;
			a[i][2]=a2;
			a[i][3]=a3;
		}
		memset(now,0,sizeof(now));
		maxn=-1;
		dfs(1);
		cout<<maxn<<endl;
	}
	
	
	
	return 0;
} 
//Ren5Jie4Di4Ling5%

