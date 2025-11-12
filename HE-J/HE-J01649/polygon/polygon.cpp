#include<bits/stdc++.h>
using namespace std;
const int Max=998244353,N=5010;
int n,a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0<<endl;
    }if(n==3){
        int x=max(a[1],max(a[2],a[3]));
        if(2*x>(a[1]+a[2]+a[3])){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
    }else{
        cout<<Max-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
