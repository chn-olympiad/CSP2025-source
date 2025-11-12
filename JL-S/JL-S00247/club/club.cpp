#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int,int> pii;
const int N=1e5+5;
int t,n,a[N][5],num[5],ans,mx[N],sc[N],id[N];
inline bool cmp(int i,int j){
    return a[i][mx[i]]-a[i][sc[i]]>a[j][mx[j]]-a[j][sc[j]];
}
void solve(){
    scanf("%d",&n);
    num[1]=num[2]=num[3]=ans=0;
    for(int i=1;i<=n;i++){
        id[i]=i;
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3]) mx[i]=1,sc[i]=2;
        else if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2]) mx[i]=1,sc[i]=3;
        else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3]) mx[i]=2,sc[i]=1;
        else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1]) mx[i]=2,sc[i]=3;
        else if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1]) mx[i]=3,sc[i]=2;
        else if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2]) mx[i]=3,sc[i]=1;
    }
    sort(id+1,id+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(num[mx[id[i]]]==(n>>1)) ans+=a[id[i]][sc[id[i]]],num[sc[id[i]]]++;
        else ans+=a[id[i]][mx[id[i]]],num[mx[id[i]]]++;
    }
    printf("%d\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}
