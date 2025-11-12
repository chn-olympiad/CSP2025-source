#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int main(){
   freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int ans = 0;
    for(int i = 1;i <= n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ans += c;
    }
    for(int i = 1;i <= n;i++){
        int p,a[1000001];
        scanf("%d",&p);
        ans += p;
        for(int j = 1;j <= n;j++){
            scanf("%d",&a[j]);
        }
    }
    printf("%d",ans);
    return 0;
}
