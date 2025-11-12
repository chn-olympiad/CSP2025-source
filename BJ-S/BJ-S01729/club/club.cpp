#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int v[5];
struct node{
    ll x,y,z,m1,m2,m3,i1,i2,i3;
}a[N];
bool cmp(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    return a.m3 > b.m3;
}
bool cmp2(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    return a.m3 < b.m3;
}
bool cmp3(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    return a.m3 > b.m3;
}
bool cmp4(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    return a.m3 < b.m3;
}
bool cmp5(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    return a.m3 > b.m3;
}
bool cmp6(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    return a.m3 < b.m3;
}
bool cmp7(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    return a.m3 > b.m3;
}
bool cmp8(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    return a.m3 < b.m3;
}
bool cmp9(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    return a.m3 > b.m3;
}
bool cmp10(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    return a.m3 < b.m3;
}
bool cmp11(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    return a.m3 > b.m3;
}
bool cmp12(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    return a.m3 < b.m3;
}
bool cmp13(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    return a.m3 > b.m3;
}
bool cmp14(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    return a.m3 < b.m3;
}
bool cmp15(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    return a.m3 > b.m3;
}
bool cmp16(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    return a.m3 < b.m3;
}
bool cmp17(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    return a.m2 > b.m2;
}
bool cmp18(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    return a.m2 < b.m2;
}
bool cmp19(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    return a.m2 > b.m2;
}
bool cmp20(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    return a.m2 < b.m2;
}
bool cmp21(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    return a.m2 > b.m2;
}
bool cmp22(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    return a.m2 < b.m2;
}
bool cmp23(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    return a.m2 > b.m2;
}
bool cmp24(node a,node b){
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    return a.m2 < b.m2;
}
bool cmp25(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    return a.m1 < b.m1;
}
bool cmp26(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    return a.m1 < b.m1;
}
bool cmp27(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    return a.m1 > b.m1;
}
bool cmp28(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    return a.m1 > b.m1;
}
bool cmp29(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    return a.m1 < b.m1;
}
bool cmp30(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    return a.m1 < b.m1;
}
bool cmp31(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    return a.m1 > b.m1;
}
bool cmp32(node a,node b){
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    return a.m1 > b.m1;
}
bool cmp33(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    return a.m2 > b.m2;
}
bool cmp34(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    return a.m2 < b.m2;
}
bool cmp35(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    return a.m2 > b.m2;
}
bool cmp36(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    return a.m2 < b.m2;
}
bool cmp37(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    return a.m2 > b.m2;
}
bool cmp38(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    if(a.m1 != b.m1)
        return a.m1 > b.m1;
    return a.m2 < b.m2;
}
bool cmp39(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    return a.m2 > b.m2;
}
bool cmp40(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    if(a.m1 != b.m1)
        return a.m1 < b.m1;
    return a.m2 < b.m2;
}
bool cmp41(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    return a.m1 > b.m1;
}
bool cmp42(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    return a.m1 < b.m1;
}
bool cmp43(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    return a.m1 > b.m1;
}
bool cmp44(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 > b.m3;
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    return a.m1 < b.m1;
}
bool cmp45(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    return a.m1 > b.m1;
}
bool cmp46(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    if(a.m2 != b.m2)
        return a.m2 > b.m2;
    return a.m1 < b.m1;
}
bool cmp47(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    return a.m1 > b.m1;
}
bool cmp48(node a,node b){
    if(a.m3 != b.m3)
        return a.m3 < b.m3;
    if(a.m2 != b.m2)
        return a.m2 < b.m2;
    return a.m1 < b.m1;
}
void solve(){
    memset(a,0,sizeof a);
    memset(v,0,sizeof v);
    ll n,ans = 0,cnt = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
        if(a[i].x >= a[i].y && a[i].x >= a[i].z){
            a[i].i1 = 1;
            if(a[i].y >= a[i].z){
                a[i].i2 = 2;
                a[i].i3 = 3;
            }
            else{
                a[i].i2 = 3;
                a[i].i3 = 2;
            }
        }
        else if(a[i].y >= a[i].x && a[i].y >= a[i].z){
            a[i].i1 = 2;
            if(a[i].x >= a[i].z){
                a[i].i2 = 1;
                a[i].i3 = 3;
            }
            else{
                a[i].i2 = 3;
                a[i].i3 = 1;
            }
        }
        else if(a[i].z >= a[i].x && a[i].z >= a[i].y){
            a[i].i1 = 3;
            if(a[i].x >= a[i].y){
                a[i].i2 = 1;
                a[i].i3 = 2;
            }
            else{
                a[i].i2 = 2;
                a[i].i3 = 1;
            }
        }
        a[i].m1 = max(max(a[i].x,a[i].y),a[i].z);
        a[i].m3 = min(min(a[i].x,a[i].y),a[i].z);
        a[i].m2 = a[i].x+a[i].y+a[i].z-a[i].m1-a[i].m3;
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp2);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
        sort(a+1,a+1+n,cmp3);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
        sort(a+1,a+1+n,cmp4);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
        sort(a+1,a+1+n,cmp5);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
        sort(a+1,a+1+n,cmp6);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
        sort(a+1,a+1+n,cmp7);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
        sort(a+1,a+1+n,cmp8);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp9);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp10);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
        sort(a+1,a+1+n,cmp11);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
        sort(a+1,a+1+n,cmp12);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
        sort(a+1,a+1+n,cmp13);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
        sort(a+1,a+1+n,cmp14);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
        sort(a+1,a+1+n,cmp15);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
        sort(a+1,a+1+n,cmp16);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp17);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp18);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp19);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp20);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp21);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp22);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp23);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp24);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp25);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp26);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp27);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp28);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp29);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp30);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp31);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp32);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp33);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp34);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp35);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp36);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp37);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp38);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp39);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp40);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp41);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp42);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp43);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp44);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp45);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp46);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp47);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    sort(a+1,a+1+n,cmp48);memset(v,0,sizeof v);
    for(int i = 1;i <= n;i++){if(v[a[i].i1] >= n/2){if(v[a[i].i2] >= n/2){v[a[i].i3]++;ans += a[i].m3;}
    else{v[a[i].i2]++;ans += a[i].m2;}}else{v[a[i].i1]++;ans += a[i].m1;}}
    cnt = max(cnt,ans);
    ans = 0;
    cout << cnt << endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
        solve();
    fclose(stdin);
    fclose(stdout);

    return 0;
}
