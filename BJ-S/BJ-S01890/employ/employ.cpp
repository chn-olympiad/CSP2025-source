#include <bits/stdc++.h>//8
using namespace std;
int n,m,a[505],b[505],p[505];
const long long mod=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    bool f=1,F=1;
    int k=0;
    for(int i=1;i<=n;i++) {scanf("%1d",&a[i]),f&=a[i]; if(a[i]&&!k) k=i;}
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    long long ans=0;
    for(int i=1;i<=n;i++) p[i]=i;
    do{
        int cnt=0,o=0;
        for(int i=1;i<=n;i++) if(a[i]&&b[p[i]]>cnt) o++; else cnt++;
        if(o>=m) ans++;
    }while(next_permutation(p+1,p+n+1));
    printf("%lld",ans);
    return 0;
}
