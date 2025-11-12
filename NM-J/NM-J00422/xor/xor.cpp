#include<bits/stdc++.h>
using namespace std;
int ans = 0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n = 0,xol;
    cin>>n>>xol;
    int xo[n];
    for(int i = 0;i<n;i++){
        cin>>xo[i];
        if(xol==0){
            if(xo[i]==0){
                ans++;
            }
        }
    }
    cout<<ans;
}
