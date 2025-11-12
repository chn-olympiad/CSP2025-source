#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int T,n;
struct node{
    int x,y,z;
    int tp;
    int c;
}a[N];
int cnt1,cnt2,cnt3;
long long ans;
int mtp;
int s[N],idx;
void solve(){
    cin>>n;
    cnt1 = cnt2 = cnt3 = 0;
    ans = 0;
    idx = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
        if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
            cnt1++;
            ans+=a[i].x;
            a[i].tp = 1;
            a[i].c = a[i].x-max(a[i].y,a[i].z);
        }else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
            cnt2++;
            ans+=a[i].y;
            a[i].tp = 2;
            a[i].c = a[i].y-max(a[i].x,a[i].z);
        }else{
            cnt3++;
            ans+=a[i].z;
            a[i].tp = 3;
            a[i].c = a[i].z-max(a[i].x,a[i].y);
        }
    }
    if(cnt1<=(n/2)&&cnt2<=(n/2)&&cnt3<=(n/2)){
        cout<<ans<<"\n";
        return;
    }
    if(cnt1>=cnt2&&cnt1>=cnt3)mtp = 1;
    else if(cnt2>=cnt1&&cnt2>=cnt3)mtp = 2;
    else mtp = 3;
    for(int i = 1;i<=n;i++){
        if(a[i].tp==mtp){
            s[++idx] = a[i].c;
        }
    }
    sort(s+1,s+idx+1);
    for(int i = 1;i<=(idx-(n/2));i++){
        ans-=s[i];
    }
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
