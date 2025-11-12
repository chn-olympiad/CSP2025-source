#include<bits/stdc++.h>
using namespace std;
int a[500010];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    int maxn=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        if(a[i]==1) cnt++;
    }
    if(maxn==1&&k==0){
        cout<<n-cnt;
        return 0;
    }
    else if(maxn==1&&k==1){
        cout<<cnt+1;
        return 0;
    }
    else if(maxn==0&&k==1){
        cout<<0;
        return 0;
    }
    else if(maxn==0&&k==0){
        cout<<n;
        return 0;
    }




    return 0;
}
