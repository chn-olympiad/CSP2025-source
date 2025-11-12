#include<bits/stdc++.h>
using namespace std;
const int N=110;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int x;
    cin>>x;
    int num=1;
    for(int i=2;i<=n*m;i++){
        int t;
        cin>>t;
        if(t>x)num++;
    }
    int c=(num-1)/n+1;
    int r=(c%2==1?num-(c-1)*n:n-(num-(c-1)*n)+1);
    cout<<c<<" "<<r<<endl;
    return 0;
}
