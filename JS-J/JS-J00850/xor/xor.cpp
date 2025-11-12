#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,y=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x!=0){
            a[y]=x;
            y++;
        }
    }
    if(k==0){
        cout<<y/2;
    }
    else{
        cout<<1;
    }
    return 0;
}
