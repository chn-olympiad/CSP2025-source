#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,js=0;
    cin>>n>>k;
    int l[n+10];
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    for(int i=1;i<=n;i++){
        int h=l[i],w=i+1;
        while(h<k&&w<=n){
                int z=l[w];
            h=h&z;
            w++;
        }
        if(h==k){
            js++;
        }
    }
    cout<<js;
    return 0;

}
