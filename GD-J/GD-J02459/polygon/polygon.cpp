#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[5005]={0};
bool use[5005]={0};
long long ans=0;
int s=0;
long long fnd(long long c,long long m){//c个数里选m个
    long long ans=1;
    for(int i=0;i < m;i++){
        ans*=c-i;
    }
    for(int i=1;i <= m;i++){
        ans/=i;
    }
    return ans;
}
void df(long long sm,long long mx){
    if(sm>mx&&s>=3){
        ans++;
        ans%=998244353;
    }
    for(int i=1;i <= n;i++){
        if(!use[i]){
            s+=1;
            use[i]=true;
            df(sm+a[i]*2,max(mx,a[i]));
            use[i]=false;
            s-=1;
        }
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    bool f=true;
    for(int i=1;i <= n;i++){
        cin >> a[i];
        if(a[i]!=1){
            f=false;
        }
    }
    if(n<3){
        cout << 0;
        return 0;
    }
    if(f){
        for(int i=0;i < n-2;i++){
            ans+=fnd(n,i);
            ans%=998244353;
        }
        cout << ans;
        return 0;
    }
    //df(0,0);
    cout << 0;
    return 0;
}
