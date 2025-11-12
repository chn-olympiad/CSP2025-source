#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,crth;cin>>n>>m;
    vector<int>a(n*m);
    for(int i=0;i<n*m;i++)cin>>a[i];
    crth=a[0];
    sort(a.rbegin(),a.rend());
    for(int i=0;i<a.size();i++){
        if(crth==a[i]){
            crth=i+1;
            break;
        }
    }
    int c=1,r=0,cnt=0;
    while(cnt<crth){
        cnt++;
        if(c%2){
            r++;
            if(r>n){
                r=n;
                c++;
            }
        }else{
            r--;
            if(r<1){
                r=1;
                c++;
            }
        }
    }
    cout<<c<<' '<<r;
    return 0;
}