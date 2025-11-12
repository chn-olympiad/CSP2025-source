#include<bits/stdc++.h>
using namespace std;int a[109];
int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,zong,c,ans,ans2;
    cin>>n>>m;int b[n+1][m+1];
    zong=n*m;
    for(int i=1;i<=zong;i++){
        cin>>a[i];
    }int ming=a[1];
    sort(a+1,a+zong+1);
    for(int i=1;i<=zong;i++){
        if(a[i]=ming){c=zong-i-1;break;}
    }
    for(int i=1;i<=m;i++){
        if(c>i*n){continue;}
        if(i%2==1){ans=c-i*n;ans2=i;}
        else{ans=m-(c-i*n);ans2=i;break;}
    }cout<<ans2<<" "<<ans/2;return 0;
}
