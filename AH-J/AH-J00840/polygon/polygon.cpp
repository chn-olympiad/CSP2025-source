#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353,N=5e3+10;
int n;
int a[N];
int cnt=0;
int b[N];
int flag[N];
void dfs(int step,int n){
    memset(b,0,sizeof(b));
    if(step==n+1){
        int mmx=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=b[i];
            mmx=max(mmx,b[i]);
        }
        if(sum>mmx*2){
            cnt++;
        }
    }
    for(int i=1;i<=n;i++){
            if(flag[a[i]]!=0){
                continue;
            }
            b[i]=a[i];
            flag[a[i]]=1;
            dfs(step+1,n);
            flag[a[i]]=0;
    }
}
signed main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","W",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];

}
if(n<=3){
    int mmx=max(max(a[1],a[2]),a[3]);
    if(a[1]+a[2]+a[3]>2*mmx){
        cout<<1;
        return 0;
    }
    cout<<0;
}
else if(n<=10){
for(int i=3;i<=n;i++){
    dfs(1,i);
}
cout<<cnt;
}
return 0;
}
