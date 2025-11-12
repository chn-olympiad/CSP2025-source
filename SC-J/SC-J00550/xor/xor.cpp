#include<bits/stdc++.h>
using namespace std;
int n,k,res,p[1048600],lst,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    memset(p,-1,sizeof(p));
    p[0]=0;
    for(int i=1,val;i<=n;i++){
        cin>>val;
        res^=val;
        if(p[res^k]>=lst){
            ans++;
            lst=i;
        }
        p[res]=i;
    }
    cout<<ans<<'\n';
    return 0;
}