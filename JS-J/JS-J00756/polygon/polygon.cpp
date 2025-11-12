#include<bits/stdc++.h>
using namespace std;
const int N =5e3+5;
int a[N];
int C(int x,int y){
    int sum=1;
    for(int i=x;i>=1;i--){
        sum*=i;
    }
    for(int i=y;i>=1;i--){
        sum/=i;
    }
    return sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n==3){
        if(a[1]+a[2]+a[3]>a[3]*2){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
        return 0;
    }
    if(a[n]==1){
        int ans=0;
        for(int i=3;i<=n;i++){
            ans+=C(n,i);
        }
        cout<<ans<<endl;
        return 0;
    }
    cout<<0<<endl;
    return 0;
}
