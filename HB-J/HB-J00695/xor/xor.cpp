#include <bits/stdc++.h>
using namespace std;
int n,k,m,sum,s,a[500000];
bool b[500000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            s=a[i];
            if(b[i]==1){
                s=k+1;
                continue;
            }
            for(int k=i+1;k<=j;k++){
                s=int(s^a[k]);
                if(b[k]==1){
                    s=k+1;
                    break;
                }
            }
            if(s==k){
                for(int k=i;k<=j;k++){
                    b[k]=1;
                }
                sum++;
            }

        }
    }
    cout<<sum;
    return 0;
}
