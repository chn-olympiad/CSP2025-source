#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int s;
    cin>>s;
    int num=1;
    int t;
    for(int i=0;i<n*m-1;i++){
        cin>>t;
        if(t>s) num++;
    }
    bool flag=num%n>0;
    cout<<num/n+(flag?1:0)<<' ';
    if((num/n+(flag?1:0))%2&&flag) cout<<num%n;
    else cout<<n-num%n+(flag?1:0);

}
