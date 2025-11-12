#include<bits/stdc++.h>
using namespace std;
int main(){
        freopen("xor.in","r",stdin);
        freopen("xor.out","w",stdout);
        long long n,k,a,x,y;
        cin>>n>>k;
        cin>>x>>y;
        for(int i=1;i<=n-2;i++){
            cin>>a;
        }
        if(x<y){
            cout<<y;
            return 0;
        }
        if(x>y){
            cout<<x;
            return 0;
        }
}
