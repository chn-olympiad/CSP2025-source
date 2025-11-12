#include<bits/stdc++.h>
using namespace std;
constexpr int N=505;
int n,m,a[N],c[N],ans,p[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) p[i]=i;
    do{
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(cnt>=c[p[i]]||!a[i]){
                cnt++;
                continue;
            }
        }
        if(n-cnt>=m) ans++;
    }while(next_permutation(p+1,p+n+1));
    printf("%d\n",ans);
    return 0;
}
