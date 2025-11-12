#include <bits/stdc++.h>
using namespace std;
int n,a[1000],sum;
bool f(int x,int y,int z){
    int ma=max(max(x,y),z);
    if((x+y+z)>(ma*2))return 1;
    return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n<=3){
        int ma=max(max(a[1],a[2]),a[3]);
        if((a[1]+a[2]+a[3])>(2*ma)){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                if(f(i,j,k))sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
