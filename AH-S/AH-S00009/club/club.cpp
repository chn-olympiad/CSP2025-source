#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+10;
struct node{
    pr mx,sc;//max,second max
}a[N];
ll T,n,cnt[4];//population
ll ans;
bool cmp(node x,node y){
    return x.mx.fi-x.sc.fi > y.mx.fi-y.sc.fi;
}
void init()
{
    memset(a,0,sizeof(a));
    memset(cnt,0,sizeof(cnt));
    ans=0;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        init();
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int x,j=1;j<=3;j++){
                cin>>x;
                if(x>=a[i].mx.fi) a[i].sc=a[i].mx,a[i].mx={x,j};
                else if(x>=a[i].sc.fi) a[i].sc={x,j}; 
            }
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            int id1=a[i].mx.se,id2=a[i].sc.se;
            if(cnt[id1]<n/2){
                cnt[id1]++;
                ans+=a[i].mx.fi;
            }else{
                cnt[id2]++;
                ans+=a[i].sc.fi;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}