#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a,k,last,ans=0;
    cin>>a>>k;
    for(int i=0;i<a;i++){
        int b;
        cin>>b;
        if(k==1&&b==1){
            ans++;
        }
        if(k==0){
            if(b==0){
                ans++;
            }
            else if(b==last){
                ans++;
            }
        }
        last=b;
    }
    cout<<ans;

    return 0;
}
