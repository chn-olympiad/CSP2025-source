#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n,ans;
int a[N],sum[N];
bool check(int s,int w){
    if(s==sum[w-1]) return 1;
    for(int i=1;i<w;i++){
        if(sum[w-1]-a[i]==s){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    if(n==3){
        cout<<(sum[2]>a[3]?1:0);
        return 0;
    }
    for(int i=3;i<=n;i++){
        int l=a[i]+1,r=sum[i-1];
        for(int j=l;j<=r;j++){
            if(check(j,i)){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
