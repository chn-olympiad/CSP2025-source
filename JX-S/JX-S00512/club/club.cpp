#include "bits/stdc++.h"
using namespace std;
const int N=2e4+5;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        int a1[N];
        int a2[N];
        int a3[N];
        long long ans=0;
        scanf("%d",&n);
        int maxx=n/2;
        for(int i=1;i<=n;i++)   scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
        sort(a1+1,a1+n+1,cmp);
        for(int num=1;num<=maxx;num++){
            ans+=a1[num];
        }
        cout<<ans;
        printf("\n");
    }
    return 0;
}
