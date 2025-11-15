#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e5+5;

struct node{
    int x, y, z;
};

bool cmpa(node a, node b){
    return a.x>b.x;
}

bool cmpb(node a, node b){
    return a.y>b.y;
}

bool cmpc(node a, node b){
    return a.z>b.z;
}

void solve(){
    int n;
    node a[maxn];
    bool flag2=true, flag3=true;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
        if (a[i].y!=0) flag2=false;
        if (a[i].z!=0) flag3=false;
    }

    if (flag2 && flag3){
        sort(a+1, a+n+1, cmpa);

        ll sum=0;
        for (int i=1;i<=n/2;i++) sum+=a[i].x;

        cout<<sum<<endl;
        return ;
    }else if (flag3){
        ll suma=0, sumb=0;

        sort(a+1, a+n+1, cmpa);
        for (int i=1;i<=n/2;i++) suma+=a[i].x;
        for (int i=n/2+1;i<=n;i++) suma+=a[i].y;

        sort(a+1, a+n+1, cmpb);
        for (int i=1;i<=n/2;i++) sumb+=a[i].y;
        for (int i=n/2+1;i<=n;i++) sumb+=a[i].x;

        ll sum=max(suma, sumb);
        cout<<sum<<endl;
        return ;
    }

    ll sum, sum1=0, sum2=0, sum3=0;

    sort(a+1, a+n+1, cmpa);
    for (int i=1;i<=n;i++) i<=n/2? sum1+=a[i].x: sum1+=max(a[i].y, a[i].z);

    sort(a+1, a+n+1, cmpb);
    for (int i=1;i<=n;i++) i<=n/2? sum2+=a[i].y: sum2+=max(a[i].x, a[i].z);

    sort(a+1, a+n+1, cmpc);
    for (int i=1;i<=n;i++) i<=n/2? sum3+=a[i].z: sum3+=max(a[i].x, a[i].y);

    sum=max(sum1, max(sum2, sum3));
    cout<<sum<<endl;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    
    int t;
    cin>>t;
    while (t--) solve();

    return 0;

    fclose(stdin);
    fclose(stdout);
}