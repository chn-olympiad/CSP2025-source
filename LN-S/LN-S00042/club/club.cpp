#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int t,n,d,ans,tot[4];
struct da{
    int a[4];
    int mx()const{
        if(d==0)return max({a[1],a[2],a[3]});
        else if(d==1)return max(a[2],a[3]);
        else if(d==2)return max(a[1],a[3]);
        else if(d==3)return max(a[1],a[2]);
    }
    int mp(){
        for(int i=1;i<=3;i++){
            if(i!=d&&a[i]==mx())return i;
        }
        return -1;
    }
    bool operator<(const da&o)const{
        return mx()>o.mx();
    }
}a[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n==2){
            int a,b,c,d,e,f;
            cin >> a >> b >> c >> d >> e >> f;
            cout << max({a+e,a+f,b+d,b+f,c+d,c+e}) << '\n';
            continue;
        }
        d=ans=tot[1]=tot[2]=tot[3]=0;
        for(int i=1;i<=n;i++){
            cin >> a[i].a[1] >> a[i].a[2] >> a[i].a[3];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            tot[a[i].mp()]++;
            ans+=a[i].mx();
            if(tot[a[i].mp()]==n/2)d=a[i].mp(),sort(a+i+1,a+n+1);
        }
        cout << ans << '\n';
    }
    return 0;
}
// please bless me
// i want 100+pts
