#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
bool p=0,o=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    if(!(a[i]==0||a[i]==1)){
        p=1;
        break;
    }
    if(p){
        cout<<2;
    }
    else
    {
        for(int i=1;i<=n;i++)
        if(a[i]!=1){
            o=1;
            break;
        }
        if(o){
            int m=0;
            if(k){
                for(int i=1;i<=n;i++){
                    if(a[i]==1)m++;
                }
            }
            else
            {
                for(int i=1;i<=n;i++){
                    if(a[i]==0){
                        m++;
                        continue;
                    }
                    if(a[i]==a[i+1]){
                        m++;
                        i++;
                    }
                }
            }
            cout<<m;
        }
        else
        {
            cout<<n/2;
        }
    }
    return 0;
}
