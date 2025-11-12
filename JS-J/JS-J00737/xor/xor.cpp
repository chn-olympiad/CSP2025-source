#include<bits/stdc++.h>
using namespace std;
int n,k,tmp,ans,g = 0;
int s[500011];
int a[500011];
int b[500011];
struct node{
    int l,r;
}t[500011];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }
    for(int i = 1;i < n;i++){
        for(int j = i;j <= n;j++){
            if(i == j) tmp = a[i];
            else tmp = s[j] ^ s[i - 1];
            if(tmp == k){
                g++;
                t[g].l = i;
                t[g].r = j;
            }
        }
    }
    ans = g;
    for(int i = 1;i <= g;i++){
        for(int j = t[i].l;j <= t[i].r;j++){
            b[j]++;
            if(b[j] > 1) ans--;
        }
    }
    cout << ans;
    return 0;
}
