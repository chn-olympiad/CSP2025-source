#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m,cnt=0;
    cin>>n>>m;
    long long a[n+5],pre[n+5]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)pre[i]=a[i];
        else{
            pre[i]=pre[i-1]^a[i];
        }
        if(pre[i]==m){
            cnt++;
            pre[i]=0;
        }
    }
    cout<<cnt;
    return 0;
}
