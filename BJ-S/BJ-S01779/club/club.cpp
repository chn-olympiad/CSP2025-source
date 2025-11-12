#include<bits/stdc++.h>
using namespace std;
namespace AfterTheRainStops{//雨停酱可爱捏，最喜欢雨停姐姐啦～
int a[100001][3],cnt[3];
int b[3][100001];
void main(){
    int n;scanf("%d",&n);cnt[0]=cnt[1]=cnt[2]=0;
    long long res=0;
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        int mx=max(a[i][0],max(a[i][1],a[i][2]));
        if(a[i][0]==mx)b[0][++cnt[0]]=max(a[i][1],a[i][2])-mx;
        else if(a[i][1]==mx)b[1][++cnt[1]]=max(a[i][0],a[i][2])-mx;
        else b[2][++cnt[2]]=max(a[i][0],a[i][1])-mx;
        res+=mx;
    }
    int o=-1;
    if(cnt[0]*2>n)o=0;
    else if(cnt[1]*2>n)o=1;
    else if(cnt[2]*2>n)o=2;
    if(o>=0){
        sort(b[o]+1,b[o]+cnt[o]+1);
        for(int i=n/2+1;i<=cnt[o];++i)res+=b[o][i];
    }printf("%lld\n",res);
}
}
int main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    int t;
    for(scanf("%d",&t);t--;AfterTheRainStops::main());
    return 0;
}