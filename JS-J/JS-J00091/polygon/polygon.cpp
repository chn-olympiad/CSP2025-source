#include<bits/stdc++.h>
using namespace std;

const int Mod=998244353;
int a[5005],n,cnt,ans;

void DFS(int idx,int select,int longest,int sum){
    if(idx>n)
    {
        if(select>=3&&sum>longest*2) ans=(ans+1)%Mod;
        return;
    }
    DFS(idx+1,select+1,max(longest,a[idx]),sum+a[idx]);
    DFS(idx+1,select,longest,sum);
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]);cnt+=a[i];}
    sort(a+1,a+n+1);
    while(cnt<=a[n]*2&&n>=3) {cnt-=a[n];n--;}
    DFS(1,0,0,0);
    cout<<ans;
    return 0;
}
