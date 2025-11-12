#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,s) for(int (i)=(s)+1;(i)<=n;(i)++)
int n;
int a[1005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]+a[3]>2*max({a[1],a[2],a[3]})){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }
    int ans=0;
    if(n==4){
        if(a[2]+a[3]+a[4]>2*a[4])ans++;if(a[1]+a[2]+a[3]+a[4]>2*a[4])ans++;
    }if(n==5){
        rep(i,1)rep(j,i)rep(k,j)rep(m,k)rep(o,m){if(a[i]+a[j]+a[k]>2*a[k])ans++;if(a[i]+a[j]+a[k]+a[m]>2*a[m])ans++;if(a[i]+a[j]+a[k]+a[m]+a[o]>2*a[o])ans++;}
}cout<<ans<<endl;}