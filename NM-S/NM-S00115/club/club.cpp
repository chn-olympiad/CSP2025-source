#include<bits/stdc++.h>
using namespace std;
int t,n,a[100050][4],b[100050],ans=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int q=1;q<=t;q++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            b[i]=a[i][1];
        }
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n/2;i++){
        ans+=b[i];
    }
    printf("%d",ans);
    return 0;
}
