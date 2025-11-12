#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,k,a[N],ans,o,z;
bool flag1 = true,flag2 = true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i] != 1) flag1 = false;
        if(a[i] != 1&&a[i]!=0) flag2 = false;
    }
    if(flag1){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=i;j++){
                ans+=1;
            }
        }
        cout<<ans;
    }
    else if(flag2){
        for(int i = 1;i<=n;i++){
            if(a[i] == 1) o++;
            else z++;
        }
        if(k==1){
            cout<<o;
        }
        else cout<<z;
    }
    return 0;
}
