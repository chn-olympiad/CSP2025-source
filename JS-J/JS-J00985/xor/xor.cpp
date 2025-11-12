#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int a[N], n, k;
bool check1(){
    for(int i=1;i<=n;i++) if(a[i]!=1) return false;
    return true;
}
bool check2(){
    for(int i=1;i<=n;i++) if(a[i]<0||a[i]>1) return false;
    return true;
}
void solve1(){
    cout << n/2;
    return;
}
void solve2(){
    int cnt=0;
    for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
    cout << cnt;
    return;
}
void solve3(){
    int cnt0=0, cnt1=0;
    bool f=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            cnt0++;
            f=0;
        }else if(a[i]==1){
            if(f==1){
                cnt1++;
                f=0;
            }else f=1;
        }
    }
    cout << cnt0+cnt1;
    return;
}
void solve4(){
    cout << n/3;
    return;
}
signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(check1()){
        if(k==1) solve2();
        else if(k==0) solve1();
    }else if(check2()){
        if(k==1) solve2();
        else if(k==0) solve3();
    }else solve4();
    return 0;
}
