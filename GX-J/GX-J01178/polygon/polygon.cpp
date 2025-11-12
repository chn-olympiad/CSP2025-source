#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon1.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    long long jishu=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n-2;i++){
        int maxn=-4.29497e+09;
        for(int j=i;j<n;j++){
            maxn=max(maxn,a[j]);
            int x=j,x1=0;
            while(x>=0){
                x1+=a[x];
                x--;
            }
            if(x1>maxn*2)
                jishu++;
        }
    }
    cout<<jishu%998244353;
    return 0;
}
