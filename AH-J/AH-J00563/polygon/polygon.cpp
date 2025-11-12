#include<bits/stdc++.h>
using namespace std;
int lenth[5010];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int lenth[n];
    for(int i=0;i<n;i++)cin>>lenth[i];
    if(n==3){
        int mx=max(lenth[0],max(lenth[1],lenth[2]));
        int sum=lenth[0]+lenth[1]+lenth[2];
        if(sum>2*mx)cout<<1;
        else cout<<0;
    }
    return 0;
}//CCF我这题真搞不了:(，n=3的时候我跪求骗点分，qql!
//RP++;
