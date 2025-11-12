#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,m,r,t,num=1;
    cin>>n>>m>>r;
    for(int i=2;i<=n*m;++i){
        cin>>t;
        if(t>r){
            ++num;
        }
    }
    num=num+n-1;
    if((num/n)%2==1){
        cout<<num/n<<" "<<num%n+1;
    }
    else if(((num+n-1)/n)%2==0){
        cout<<num/n<<" "<<n-(num%n);
    }
    return 0;
}
