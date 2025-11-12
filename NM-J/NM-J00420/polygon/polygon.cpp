#include <bits/stdc++.h>
using namespace std;

int ii,n,sss = 0,aa[5005] = {0},bb[5005] = {0};

void ct(int ss){
    int s = 0,mm = 0;
    for(int i = ii;i<=ss;i++){
        s+=aa[i];
        mm = max(mm,aa[i]);
    }
    if(s>2*mm) sss++;
}

void f(int a,int k){
    if(k>=3) ct(k+ii-1);
    if(a>=n) return;
    for(int i = a+1;i<=n;i++){
        bb[a+1] = aa[i];
        f(i,k+1);
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++) cin >> aa[i];
    bb[1] = aa[1];bb[2] = aa[2];bb[3] = aa[3];
    for(ii = 1;ii<=n-2;ii++){
        f(ii,1);
        for(int i = 1;i<=n;i++) bb[i] = 0;
    }
    cout << sss;
    return 0;
}