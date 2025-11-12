#include<bits/stdc++.h>
using namespace std;
int n,b,s;
int a[5010];

int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
                if(a[j]==0){
                    break;
                }
                b=0;
            for(int k=j+i-1;k>=j;k--){
                b+=a[k];
            }
            if(b>2*a[j]){
                s++;
            }
        }
    }
    n=n-2;
    while(n){
        s+=n-1;
        n--;
    }
    cout<<s%998244353;
    return 0;
}
