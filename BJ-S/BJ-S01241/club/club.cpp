#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
const int N=1e5+5;
ll t,n,a[N][5],m1[N],m2[N],mx2[N],mx1[N],c[N];
struct node{
    ll pos,num;
    bool operator <(node b){
        return num>b.num;
    }
}b[5],cnt[5];
bool cmp(ll A,ll B){return A>B;}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ll ans=0;
        cin>>n;
        for(int i=1;i<=3;i++){
            cnt[i].pos=i;
            cnt[i].num=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            for(int j=1;j<=3;j++){
                b[j].num=a[i][j];
                b[j].pos=j;
            }
            sort(b+1,b+4);
            m1[i]=b[1].pos,m2[i]=b[2].pos;
            mx1[i]=b[1].num,mx2[i]=b[2].num;
            ans+=b[1].num;
            cnt[b[1].pos].num++;
        }
        sort(cnt+1,cnt+4);
        if(cnt[1].num<=n/2){
            cout<<ans<<"\n";
        }
        else{
            ll cur=0;
            for(int i=1;i<=n;i++){
                if(m1[i]==cnt[1].pos){
                    c[++cur]=mx1[i]-mx2[i];
                }
            }
            sort(c+1,c+cur+1);
            ll cur2=cnt[1].num-n/2;
            for(int i=1;i<=cur2;i++)ans-=c[i];
            cout<<ans<<"\n";
        }
    }
    return 0;
}