#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;

int T;
long long n,ans=0,max1=-1;

int z[maxn];
struct node{
    int b[5];
};
node a[maxn];

bool pd(){
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=n;i++){
        if(z[i]==1)
            cnt1++;
        if(z[i]==2)
            cnt2++;
        if(z[i]==3)
            cnt3++;
    }
    int mid1 = n/2;
    if(cnt1>mid1||cnt2>mid1||cnt3>mid1){
        return 0;
    }
    return 1;
}

void js(){
    ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[i].b[z[i]];
    }
    max1 = max(max1,ans);
}

void dfs(int dep){
    if(dep>n){
        if(pd())
            js();
        return;
    }
    for(int i=1;i<=3;i++){
        z[dep]=i;
        dfs(dep+1);
    }
}

int main(){
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--){
        max1 = 0;
        ans = 0;
        cin >> n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin >> a[i].b[j];
            }
        }
        dfs(1);
        cout << max1 << endl;
    }
    return 0;
}