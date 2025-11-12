#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
bool ok(int tot,int mx){
    return (tot>2*mx);
}
void dfs(int step,int last,int tot,int mx){
    if(step>3){
        if(ok(tot,mx)==1){
            ans++;
            ans=ans%998244353;
        }
    }
    for(int i=last+1;i<=n;i++){
        dfs(step+1,i,tot+a[i],max(mx,a[i]));
    }
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    bool right1=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) right1=0;
    }
    if(right1==1){

        cout<<n/3;
    }else if(n==3){
        int totx=0,maxx=0;
        for(int i=1;i<=n;i++){
            totx+=a[i];
            maxx=max(maxx,a[i]);
        }
        if(totx>2*maxx) cout<<1;
        else cout<<0;
    }else{
        dfs(1,0,0,0);
        cout<<ans;
    }
	return 0;
}
