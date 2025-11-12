#include<bits/stdc++.h>
using namespace std;
int s[100000005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a,&b,&c);
            s[t]+=a;
        }
    }
    for(int i=1;i<=t;i++){
        printf("%d",&s[i]);
    }
    return 0;
}
