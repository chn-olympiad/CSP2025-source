#include<iostream>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    int x,ma;
    int ans=0;
    for(int i=1;i<=n*m;i++)
    {
        cin>>x;
        if(i==1)ma=x;
        else if(x>ma)ans++;
    }
    ans+=1;
    int li=0;
    while(ans>n){
        ans-=n;
        li++;
    }
    li++;
    cout<<li<<" ";
    if(li%2==1){
         cout<<ans;
    }else{
        cout<<n-ans+1;
    }
    return 0;
}
