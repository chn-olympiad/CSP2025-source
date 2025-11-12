#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int cnt=1;
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]) cnt++;
    }
    int ans1=0,ans2=0;
    if(cnt%n==0){
        ans2=cnt/n;
        ans1=cnt%n+1;
    }
    else{
        ans2=cnt/n+1;
        ans1=cnt%n;
    }
    if(ans2%2==1) cout<<ans2<<' '<<ans1;
    else cout<<ans2<<' '<<n-ans1+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
