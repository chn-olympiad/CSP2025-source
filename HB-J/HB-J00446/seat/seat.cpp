#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n*m+5]={},R;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    R=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int ti=0;
    int p=1;
    for(int c=1;c<=n;c++){
        for(int r=1;r<=n;r++)
            if(a[p++]==R){
                cout<<c<<" "<<r;
                return 0;
            }
        c++;
        if(c>m)break;
        for(int r=n;r>=1;r--)
            if(a[p++]==R){
                cout<<c<<" "<<r;
                return 0;
            }
    }
    return 0;
}
