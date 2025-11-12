#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[1000000];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(k==0){
        map<int,int>c;
        for(int i=1;i<=n;i++)c[a[i]]++;
        cout<<c[1]/2+c[0]/2;
    }if(k==1){
        int ans=0;
        map<int,int>c;
        for(int i=1;i<=n;i++)c[a[i]]++;
        ans+=min(c[1],c[0]);
        if(c[1]>c[0])ans+=(c[1]-c[0])/4;
        if(c[0]>c[1])ans+=(c[0]-c[1])/4;
        cout<<ans;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}

