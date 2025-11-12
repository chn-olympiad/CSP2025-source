#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9;
int T,n,m;
struct Node{
    ll num,idx;
}a[N][5];
ll ans;
ll cnt1,cnt2,cnt3;
bool check1,check2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("club.in","r",stdin);
   // freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        m=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i][1].num>>a[i][2].num>>a[i][3].num;
            a[i][1].idx=1,a[i][3].idx=2,a[i][3].idx=1;
            a[i][0].num=max(a[i][1].num,max(a[i][2].num,a[i][3].num));
            if(a[i][0].num==a[i][1].num) a[i][0].idx==a[i][1].idx;
            else if(a[i][0].num==a[i][2].num) a[i][0].idx==a[i][2].idx;
            else a[i][0].idx==a[i][3].idx;
            a[i][4].num=max(min(a[i][1].num,a[i][2].num),min(a[i][2].num,a[i][3].num));
            if(a[i][4].num==a[i][1].num) a[i][4].idx==a[i][1].idx;
            else if(a[i][4].num==a[i][2].num) a[i][4].idx==a[i][2].idx;
            else a[i][4].idx==a[i][3].idx;
            a[i][4].num-=a[i][0].num;
            a[i][5].num=min(a[i][1].num,min(a[i][2].num,a[i][3].num));
            if(a[i][5].num==a[i][1].num) a[i][5].idx==a[i][1].idx;
            else if(a[i][5].num==a[i][2].num) a[i][5].idx==a[i][2].idx;
            else a[i][5].idx==a[i][3].idx;
            a[i][5].num-=a[i][0].num;
        }
        for(int i=1;i<=n;i++){
            ans+=a[i][0].num;
            if(a[i][0].idx==1) cnt1++;
            else if(a[i][0].idx==2) cnt2=++;
            else cnt3++;
        }
    }
    return 0;
}
