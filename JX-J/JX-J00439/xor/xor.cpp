#include<iostream>
using namespace std;
const int MAXN=5e5+1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.ans","w",stdout);
    int n,k,a[MAXN]={},d[MAXN]={};

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=d[i-1]^a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((d[i-1]^d[j])==k){
                cout<<i<<' '<<j<<endl;
                ans++;
                i=j;
                break;
            }
        }
    }
    cout<<ans;
}
