#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> s(n*m);
    for(int &rp:s)cin>>rp;
    int r=s.front();
    sort(s.begin(),s.end());
    int pos=n*m-(lower_bound(s.begin(),s.end(),r)-s.begin());
    int x=ceil(1.0*pos/n);
    cout<<x<<" ";
    if(x%2==0){
        if(pos%n==0)cout<<1;
        else cout<<n-(pos%n)+1;
    }
    else{
        if(pos%n==0)cout<<n;
        else cout<<pos%n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
