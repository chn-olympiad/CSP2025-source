#include <bits/stdc++.h>
using namespace std;
struct st{
    long long num=0,to=0;
}a[100050][5];
struct fl{
    long long cha=0,id=0;
}k[100050];
bool cmp1(st l,st r){
    return l.num>r.num;
}
bool cmp2(fl l,fl r){
    return l.cha>r.cha;
}
int t,n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        long long ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1].num>>a[i][2].num>>a[i][3].num;
            a[i][1].to=1;
            a[i][2].to=2;
            a[i][3].to=3;
            sort(a[i]+1,a[i]+3+1,cmp1);
            k[i].id=i;
            k[i].cha=a[i][1].num-a[i][2].num;
        }
        sort(k+1,k+n+1,cmp2);
        int  vis[5]={};
        for(int o=1;o<=n;o++){
            int i=k[o].id;
            if(vis[a[i][1].to]==n/2){
                ans+=a[i][2].num;
                vis[a[i][2].to]++;
            }else{
                ans+=a[i][1].num;
                vis[a[i][1].to]++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
