#include<bits/stdc++.h>
using namespace std;
int maxx = -1;
int he,n;
int a[5005];
long long res = 0;
long long blmx(int now,int he,int maxxx,int countss){
    //he += a[now];
    if(now == n-1){
        if((he + a[now] > (maxxx * 2)) && countss >= 3){
            res++;
        }

        return 0;
    }
    if((he + a[now] > (maxxx * 2)) && countss >= 3){
        res++;
    }
    for(int j = now + 1;j<n;j++){
        blmx(j,he + a[now],max(maxxx,a[j]),countss+1);
    }
    return res % 998244353;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        maxx= max(maxx,a[i]);
        he+=a[i];
    }
    if(maxx == 1){
        cout<<0<<endl;
        return 0;
    }
    if(n == 3){
        if(he > maxx * 2) cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }


    for(int i = 0;i<n;i++){
        blmx(i,0,a[i],1);
    }
    cout<<res % 998244353<<endl;
    return 0;
}
