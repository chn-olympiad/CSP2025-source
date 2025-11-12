#include<bits/stdc++.h>
using namespace std;
int a[5001],n;
int maax=-1;
int ans,sum;
void dfs(int x,int step,int he,int maxx){
    if(step>=3&&he>2*maxx){
	    ans++;
	    ans%=998244353;
	}
	if(maxx>maax) return;
	for(int i=x+1;i<=n;i++){
		dfs(i,step+1,he+a[i],max(maxx,a[i]));
	}
	return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maax=max(a[i],maax);
        sum+=a[i];
    }
    if(maax==1){
		int cnt=1;
	    for(int i=1;i<n;i++){
		    cnt*=2;
		    cnt%=998244353;
		}
		cnt=cnt-1-n-n*(n-1)/2;
		if(cnt<0) cnt+=998244353;
		ans=cnt;
	}
    else{
		maax=(sum-1)/2;
	    dfs(0,0,0,0);
	}
    cout<<ans;
    return 0;
}
