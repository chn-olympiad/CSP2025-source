#include<bits/stdc++.h>
using namespace std;
long long n,a[50005],ans=0;
void dfs(long long id,long long mx,long long cnt,long long la){
    ans=ans%(998*244*353);
    if(id>=3&&cnt>2*mx){
        ans++;
    }
    for(int i=la+1;i<=n;i++){
        dfs(id+1,max(mx,a[i]),cnt+a[i],i);
    }
}
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(0,0,0,0);
    cout<<ans;
    return 0;
}
