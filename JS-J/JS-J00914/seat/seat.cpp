#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int sb=0;
    int a[109];
    for(int i=1;i<=n*m;++i){
        cin>>a[i];
    }
    sb=a[1];
    sort(a+1,a+n*m+1);
    int weizhi;
    for(int i=n*m;i>0;--i){
        if(a[i]==sb){
            weizhi=n*m-i+1;
        }

    }
    int hangshu;
    if(weizhi%n==0){
        cout<<weizhi/n;
        hangshu=weizhi/n;
    }
    else{
        cout<<weizhi/n+1;
        hangshu=weizhi/n+1;
    }
    cout<<" ";
    if(hangshu%2==1){
        if(weizhi%n==0){
            cout<<n;
        }
        else{
            cout<<weizhi%n;
        }
    }
    else{
        cout<<n-weizhi%n+1;
    }
    return 0;
}
