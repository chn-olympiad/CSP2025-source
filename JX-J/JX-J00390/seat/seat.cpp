#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,cnt,fs,a,ans1,ans2;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>fs;
    cnt=1;
    for(int i=2;i<=n*m;i++){
        cin>>a;
        if(a>fs)cnt++;
    }
    ans1=(cnt+n-1)/n;
    if(cnt%n==0){
        ans2=n;
    }
    else{
        ans2=cnt%n;
    }
    if(ans1%2==0){
        ans2=n+1-ans2;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
    }

