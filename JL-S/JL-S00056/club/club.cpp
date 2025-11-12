#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define mkp make_pair
#define fi first
#define se second
const int N=400024;
int t,n,m,ans;
struct node{
    int a,b,c,diff,pl;
}a[N];
bool cmp(node x,node y){
    if(x.pl==y.pl) return x.diff<y.diff;
    return x.pl>y.pl;
}
int cnt[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cnt[1]=0;
        cnt[2]=0;
        cnt[3]=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            int maxn=a[i].a,id=1;
            if(a[i].b>maxn){
                maxn=a[i].b;
                id=2;
            }
            if(a[i].c>maxn){
                maxn=a[i].c;
                id=3;
            }
            a[i].pl=id;
            cnt[id]++;
            ans+=maxn;
        }
        if(cnt[1]<=n/2){
            if(cnt[2]<=n/2){
                if(cnt[3]<=n/2){
                    cout<<ans<<"\n";
                }
                else{
                    for(int i=1;i<=n;i++){
                        if(a[i].pl!=3){
                            a[i].pl=0;
                            continue;
                        }
                        a[i].diff=min(a[i].c-a[i].a,a[i].c-a[i].b);
                    }
                    sort(a+1,a+1+n,cmp);
                    int cur=0;
                    while(cnt[3]>n/2){
                        cur++;
                        cnt[3]--;
                        ans-=a[cur].diff;
                    }
                    cout<<ans<<"\n";
                }
            }
            else{
                for(int i=1;i<=n;i++){
                    if(a[i].pl!=2){
                        a[i].pl=0;
                        continue;
                    }
                    a[i].diff=min(a[i].b-a[i].a,a[i].b-a[i].c);
                }
                sort(a+1,a+1+n,cmp);
                int cur=0;
                while(cnt[2]>n/2){
                    cur++;
                    cnt[2]--;
                    ans-=a[cur].diff;
                }
                cout<<ans<<"\n";
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(a[i].pl!=1){
                    a[i].pl=0;
                    continue;
                }
                a[i].diff=min(a[i].a-a[i].b,a[i].a-a[i].c);
            }
            sort(a+1,a+1+n,cmp);
            int cur=0;
            while(cnt[1]>n/2){
                cur++;
                cnt[1]--;
                ans-=a[cur].diff;
            }
            cout<<ans<<"\n";
        }
    }
}