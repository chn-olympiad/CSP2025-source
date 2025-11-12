#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,a[5010],ml[5010];
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        ml[a[i]]=2*a[i];
    }if(n<3){
        cout<<0;
        return 0;
    }if(n==3){
        if(a[0]+a[1]+a[2]<2*max(a[0],max(a[1],a[2]))){
            cout<<0;
        }else{
            cout<<1;
        }
        return 0;
    }cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
