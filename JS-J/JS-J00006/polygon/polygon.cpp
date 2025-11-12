#include<bits/stdc++.h>
#define ll long long
#define N 1000010
using namespace std;
ll n,a[N],cnt;
void dfs(ll k,ll ma,ll m,ll sum){
    if(k>n){
        if(sum>ma*2&&m>=3){
            cnt++;
        }
        return ;
    }
    dfs(k+1,max(ma,a[k]),m+1,a[k]+sum);
    dfs(k+1,ma,m,sum);
}
void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
