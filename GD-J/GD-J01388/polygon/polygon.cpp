#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5010],ans;
void dfs(ll p,ll cnt,ll pre,ll ma){
	if(p>n){
		if(cnt>=3&&pre>ma*2)
		    ans++;
		if(ans==998244353) 
		    ans=0;
		return;
	}
	dfs(p+1,cnt+1,pre+a[p],max(ma,a[p]));
	dfs(p+1,cnt,pre,ma);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0,0,0);
    cout<<ans;
	return 0;
} 
