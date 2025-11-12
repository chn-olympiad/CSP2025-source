#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5;
int a[N],ans,cnt,maxx=-10,cnt1,f;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=(1<<n)-1;i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                cnt++;
                cnt1+=a[j+1];
                maxx=max(maxx,a[j+1]);
            }
        }
        if(cnt>=3){
            if(cnt1>maxx*2){
                ans++;
            }
        }
        cnt1=0;
        maxx=-10;
        cnt=0;
    }
    cout<<ans;
    return 0;
}
