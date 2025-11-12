#include<bits/stdc++.h>
using namespace std;
int a[100010];
int cnt,n,maxx;
int dp(int s){
    int x=0;
    for(int i=s;i<=n;i++){
        x+=a[i];
        dp(s+x);
        cnt+=1;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    sort(a+1,a+1+n);
    if(n<=3){
        if(a[3]<a[1]+a[2]){
            cnt++;
        }
    }else if(maxx==1){
        dp(2);
        cnt-=n;
        cnt++;
    }
    cout<<cnt;
    return 0;
}
