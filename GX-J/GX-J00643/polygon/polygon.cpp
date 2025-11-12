#include<bits/stdc++.h>
using namespace std;
int n,a[5003],ans=0;
bool v[5003][5003];
int f(int l,int r){
    if(l>r)swap(l,r);
    if((r-l+1)<3)return 0;
    int sum=0,max_=-1;
    for(int i=l;i<=r;i++){
        sum+=a[i];
        max_=max(max_,a[i]);
    }
    cout<<l<<' '<<r<<endl;
    return (sum>2*max_?1:0);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                ans+=f(i,j);
                ans%=998244353;
            }
        }
    }
    cout<<ans+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
