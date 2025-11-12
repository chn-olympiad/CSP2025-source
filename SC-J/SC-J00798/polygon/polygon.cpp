#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
bool xz[100005]={0};
int qweasd[100005];
void dfs(int step){
	if(step>n){
        int cnt=0,q=0;
        int maxn=-10005;
		for(int i=1;i<=n;i++){
            if(xz[i]==1){
                q++;
                maxn=max(maxn,qweasd[i]);
                cnt+=qweasd[i];
            }
		}
		if(cnt>maxn*2 and q>=3) ans++;
		return ;
	}else{
	    dfs(step+1);
		xz[step]=1;
		dfs(step+1);
		xz[step]=0;
	}
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>qweasd[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
