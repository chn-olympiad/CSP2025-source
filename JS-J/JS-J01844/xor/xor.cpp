#include<bits/stdc++.h>
using namespace std;
int n,k,x[500001];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>x[i];
    }
    int ans=0,start=0;
    while(true){
        bool is_ok=0;
        int i;
        for(i=start;i<n;++i){
            int xor_=0;
            for(int j=i;j>=start;--j){
                xor_^=x[j];
                if(xor_==k){
                    is_ok=1;
                    break;
                }
            }
            if(is_ok){
                break;
            }
        }
        if(!is_ok){
            break;
        }
        start=i+1;
        ++ans;
    }
    cout<<ans<<'\n';
    return 0;
}
