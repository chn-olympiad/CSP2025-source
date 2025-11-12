#include <bits/stdc++.h>
using namespace std;
int n,cnt,mod=998244353;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for (int i=1;i<(1<<n);i++){
        int x=i,num=0,idx=0;
        while (x){
            int bt=(1<<idx);
            if (x&bt){
                num+=a[idx];
                x-=bt;
            }
            idx++;
        }
        if (num>a[idx-1]*2){
            cnt++;
            cnt%=mod;
        }
    }
    cout<<cnt;
    return 0;
}

