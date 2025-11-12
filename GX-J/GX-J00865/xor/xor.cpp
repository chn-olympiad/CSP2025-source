#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn];
bool b[maxn];
int n, k;
int ans = 0;
int ne = 1;

bool f(){
    for(int i=1;i<=n;i++){
        if(b[i] == 0){
            ne = i;
            return 0;
        }
    }
    return 1;
}

bool jud(int l, int r){
    for(int i=l;i<=r;i++){
        if(b[i] == 1) return 0;
    }
    return 1;
}

bool p(int l, int r){
    if(!jud(l,r)) return 0;
    int tot = a[l];
    for(int i=l+1;i<=r;i++){
        tot = (tot ^ a[i]);
    }
    if(tot == k) return 1;
    return 0;
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    //tanxin
    for(int l = 1;l<=n;l++){//length
        for(int i=ne;i<=n-l+1;i++){
            if(p(i, i+l-1)){
                ans ++;
                for(int j=i;j<=i+l-1;j++) b[i] = 1;
            }
        }
        if(f()) break;
    }
    cout<<ans;


    return 0;
}
