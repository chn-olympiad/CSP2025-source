#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define LL long long
int n,ans;
const int MOD=998244353;
int l[5100];
void dfs(int now,int sum,int cnt,int maxx){
	if(now==n+1){
		if(cnt>=3&&sum>2*maxx)ans++;
		ans%=MOD;
		return;
	}
	dfs(now+1,sum+l[now],cnt+1,max(maxx,l[now]));
	dfs(now+1,sum,cnt,maxx);
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)cin>>l[i],sum+=l[i];
    dfs(1,0,0,0);
    cout<<ans%MOD<<"\n";
    return 0;
}
/*
5
2 2 3 8 10

6

 
*/
