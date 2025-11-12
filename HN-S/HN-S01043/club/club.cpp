#include<bits/stdc++.h>
using namespace std;
const int N=100000+5;
int n;
struct node{
    int x[3];
    int chosed;
    int cst;
    int delt;
}a[N];
int ton[3];
int T;
bool cmp(node A,node B){
    return A.delt>B.delt;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){ 
        cin>>a[i].x[0]>>a[i].x[1]>>a[i].x[2];
        a[i].chosed=0;
        if(a[i].x[1]>a[i].x[a[i].chosed]) a[i].chosed=1;
        if(a[i].x[2]>a[i].x[a[i].chosed]) a[i].chosed=2;
    }
    for(int i=1;i<=n;i++) ton[a[i].chosed]++,a[i].cst=a[i].x[a[i].chosed];
    int td=0;
    if(ton[1]>ton[td]) td=1;
    if(ton[2]>ton[td]) td=2;
    
    for(int i=1;i<=n;i++){
        if(a[i].chosed!=td) a[i].delt=-100000005;
        else a[i].delt=max(a[i].x[(td+1)%3]-a[i].x[td],a[i].x[(td+2)%3]-a[i].x[td]);
    }
    sort(a+1,a+n+1,cmp);
    int cnt=0;
    while(ton[td]>n/2){
        cnt++;
        a[cnt].cst+=a[cnt].delt;
        ton[td]--;
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=a[i].cst;
    cout<<ans<<"\n";
    ans=0;
    ton[0]=ton[1]=ton[2]=0;
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}