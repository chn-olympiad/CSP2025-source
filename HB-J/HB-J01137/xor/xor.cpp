#include <bits/stdc++.h>
using namespace std;
int a[500005],n,k,t[500005][2];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int te,j,m=-1;
    for(int i=0;i<n;i++){
        j=i;
        te=0;
        for(;j<n;j++){
            te=te^a[j];
            if(te==k)break;
        }
        if(j<n){
            t[++m][0]=i;
            t[m][1]=j;
        }
    }
    int st=-1,fn,cnt=0;
    for(;;){
        for(j=0,fn=1000000;j<=m;j++){
            if(t[j][0]>st&&t[j][1]<fn){
                fn=t[j][1];
            }
        }
        if(fn==1000000)break;
        cnt++;
        st=fn;
    }
    cout << cnt;
    return 0;
}
