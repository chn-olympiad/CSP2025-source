#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105][105],num[10005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int number;
    cin>>number;
    num[1]=number;
    for(int i=2;i<=n*m;i++) cin>>num[i];
    sort(num+1,num+n*m+1);
    int s=n*m-(upper_bound(num+1,num+n*m+1,number)-2-num);
    //cout<<s<<" ";
    cout<<s/n+1<<" ";
    int ans=s%4;
    if(ans<=0) ans=4;
    if((s/n+1)%2==0){
        cout<<5-ans;
    }
    else {
        cout<<ans;
    }
    return 0;
}
