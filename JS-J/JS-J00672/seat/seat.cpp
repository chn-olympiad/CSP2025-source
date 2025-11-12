#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],cnt,ans1=1,ans2=0,zj=1,fl=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    cnt=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        ans2+=zj;
        if(ans1!=1) fl=1;
        if(ans2>m||ans2<1&&fl==1){
            if(ans1%2==1){
                ans1++;
                ans2=n;
                zj=-1;
            }else{
                ans1++;
                ans2=1;
                zj=1;
            }
        }
        if(a[i]==cnt){
            cout<<ans1<<' '<<ans2;
            return 0;
        }
    }
    return 0;
}
