//GZ-S00482 贵州师范大学云岩实验中学 陈钧雷
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n,m,pp=0,lim=0;
char d[505];
ull p[505];
ull ans;
const ull mod=998244353;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(ull i=0;i<n;i++) cin>>d[i];
    for(ull i=0;i<n;i++) cin>>p[i];
    for(ull i=0;i<n;i++) p[i]+=500*i;
    sort(p,p+n);
    do{
        pp=0,lim=0;
        for(int i=0;i<n;i++) if((d[i]=='0')||p[i]%500<=lim) lim++;
        else pp++;
        if(pp>=m) ans++;
    }while(next_permutation(p,p+n));
    cout<<ans;
    return 0;
}