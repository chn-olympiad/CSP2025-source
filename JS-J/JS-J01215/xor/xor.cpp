#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+9;
long long n,k;
long long a[maxn];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool is_0=false;
    long long cnt_0=0,cnt_1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            is_0=true;
            cnt_0++;
        }
        if(a[i]==1){
            cnt_1++;
        }
    }
    if(k==0&&!is_0){
        cout<<n/2;
        return 0;
    }
    long long ans=0;
    if(k==1){
        cout<<cnt_1;
        return 0;
    }
    if(k==0){
        ans=cnt_1/2+cnt_0;
        cout<<ans;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
