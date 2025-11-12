#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt;
bool b[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        long long t=a[i];
        for(long long j=i;j>=0;j--){
            if(b[j])break;
            if(t==m){
//                cout<<j<<' '<<i<<endl;
                cnt++;
                b[j]=b[i]=1;
                break;
            }
            t^=a[j-1];
        }
    }
    cout<<cnt;
    return 0;
}
