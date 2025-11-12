#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=2e4+5;
int cnt_1=0,cnt_2=0,cnt_3=0,n;
long long ans=0;
struct Node{
    int a1,a2,a3;
    int cha;
    bool chosen=0;
}a[N];
void dfs(int x,long long cnt){
    if(x==n+1){
        ans=max(ans,cnt);
        return;
    }
    for(int i=1;i<=3;i++){
        if(cnt_1==n/2&&i==1){
            continue;
        }if(cnt_2==n/2&&i==2){
            continue;
        }if(cnt_3==n/2&&i==3){
            continue;
        }
        if(i==1) cnt_1++,cnt+=a[x].a1;
        if(i==2) cnt_2++,cnt+=a[x].a2;
        if(i==3) cnt_3++,cnt+=a[x].a3;
        dfs(x+1,cnt);
        if(i==1) cnt_1--,cnt-=a[x].a1;
        if(i==2) cnt_2--,cnt-=a[x].a2;
        if(i==3) cnt_3--,cnt-=a[x].a3;
    }
}bool cmp1(Node &x,Node &y){
    if(x.a1!=y.a1){
        return x.a1>y.a1;
    }else{
        return x.cha<y.cha;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cnt_1=0,cnt_2=0,cnt_3=0;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            a[i].cha=abs(a[i].a1-a[i].a2);
        }
        if(n<=13){
            dfs(1,0);
            cout<<ans<<endl;
        }else{
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=n;i++){
                if(a[i].a1>=a[i].a2){
                    ans+=a[i].a1;
                    if(cnt_1>n/2){
                        cnt_1--;
                        ans-=a[i].a1;
                        ans+=a[i].a2;
                    }a[i].chosen=1;
                }
            }for(int i=1;i<=n;i++){
                if(!a[i].chosen){
                    ans+=a[i].a2;
                }
            }cout<<ans<<endl;
        }
    }
    return 0;
}
