#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int MOD=998244353;
bool flag1=true,flag2=true;
int n,m,k,cnt1=0;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag1=false;
        if(a[i]>=2) flag2=false;
        if(a[i]==1) cnt1++;
    }
    if(flag1){
        cout<<n/2<<endl;
        return 0;
    }
    if(flag2){
        if(k==0){
            int ans1=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans1++;
                if(a[i]==1&&a[i+1]==1){
                    ans1++;
                    a[i]=2;
                    a[i+1]=2;
                }
            }
            cout<<ans1<<endl;
            return 0;

        }
        else{
            cout<<cnt1<<endl;
        }
    }
}
