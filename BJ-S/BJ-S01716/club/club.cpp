#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+5;
int t,n,idx[N],cnt[3],ans;
struct node{
    int val,id;
}a[N][3];
bool cmp(node a,node b){
    return a.val>b.val;
}
void solve(){
    for(int j=0;j<3;j++) cnt[j]=0;
    ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i][0].val,&a[i][1].val,&a[i][2].val);
        for(int j=0;j<3;j++) a[i][j].id=j;
        sort(a[i],a[i]+3,cmp);
        idx[i]=a[i][0].id;
        ans+=a[i][0].val;
        cnt[idx[i]]++;
    }
    for(int j=0;j<3;j++){
        if(cnt[j]>n/2){
            vector<int>v;
            for(int i=1;i<=n;i++){
                if(idx[i]==j) v.push_back(a[i][0].val-a[i][1].val);
            }
            sort(v.begin(),v.end());
            for(int i=0;i<cnt[j]-n/2;i++) ans-=v[i];
            break;
        }
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
