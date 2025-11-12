#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k;
int f(int l,int r,int z){
    int s = a[l],m;
    for(int i = l + 1;i <= r;i++){
        s = s ^ a[i];
    }
    if(s == k){
        z++;
    }
    m = z;
    for(int i = r + 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            m = max(m,f(i,j,z));
        }
    }
    return m;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int ma = 0;
    for(int i = 1;i <= n;i++){
        ma = max(ma,f(1,i,0));
    }
    cout << ma;
    return 0;
}
