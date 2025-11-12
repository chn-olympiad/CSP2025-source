#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b,c,d;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        for(int i=1;i<=3;i++){
            if(i==1)b=a[i];
            if(i==2)c=a[i];
            if(i==3)d=a[i];
        }
        if(c+d>b&&c+b>d&&b+d>c)cout<<"1";
        else cout<<"0";
    }
    else cout<<"0";
    return 0;
    //唉，只能骗点分了（bushi);
}
