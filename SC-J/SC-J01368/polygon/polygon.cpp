#include <bits/stdc++.h>
using namespace std;
int n,m,an,k=3;
int a[5005];
int b[5005];
void dfs(int ans,int now){
    if(now>k){
        int sum=0,ma=-1;
        for(int i=1;i<now;i++){
            sum+=b[i];
            ma=max(ma,b[i]);
        }
        //cout<<sum<<" "<<ma<<endl;
        if(sum>2*ma)an++;
        return;
    }
    if(ans<=n){
        b[now]=a[ans];
        dfs(ans+1,now+1);
        dfs(ans+1,now);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(;k<=n;k++)dfs(1,1);
    cout<<an;
    return 0;
}