#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1048576 + 1;
int last[N];
struct Node{
    int l,r;
}a[500010];
bool cmp(Node x,Node y){
    return x.r < y.r;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,k,sum = 0,len = 0;
    cin >> n >> k;
    last[0] = 1;
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        sum ^= x;
        x = sum ^ k;
        if(last[x]){
            len++;
            a[len].l = last[x];
            a[len].r = i;
            last[x] = 0;
        }
        last[sum] = i + 1;
    }
    int lst = 0,cnt = 0;
    for(int i = 1;i <= len;i++){
        if(lst >= a[i].l) continue;
        cnt++;
        lst = a[i].r;
    }
    cout << cnt << '\n';
    return 0;
}