#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,a[N],cnt,sum,x=1;
bool flag=true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            flag=false;
        }
    }
    if(flag){
        cout<<n/2;
        return 0;
    }
    while(x<=n){
        if(a[x]==k){
            cnt++;
            x++;
        }
        else{
            sum=a[x];
            x++;
            while(x<=n){
                sum=(sum^a[x]);
                if(sum==k){
                    cnt++;
                }
                x++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
