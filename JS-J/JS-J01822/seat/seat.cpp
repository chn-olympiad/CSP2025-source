#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int Q=n*m;
    for(int i=1;i<=Q;i++){
        cin>>a[i];
    }
    int x=a[1],cnt=0,ans1=0,ans2=0;
    sort(a+1,a+Q+1,greater<int>());
    for(int i=1;i<=Q;i++){
        if(a[i]==x){
            cnt=i;
            break;
        }
    }
    ans1=(cnt+n-1)/n;
    ans2=cnt-(ans1-1)*n;
    if(ans1%2==0){
        if(ans2==0){
            cout<<ans1<<" "<<ans2+1;
        }else{
            cout<<ans1<<" "<<n-ans2+1;
        }
    }else{
        if(ans2==0){
            cout<<ans1<<" "<<n-ans2;
        }else{
            cout<<ans1<<" "<<ans2;
        }
    }
    return 0;
}
