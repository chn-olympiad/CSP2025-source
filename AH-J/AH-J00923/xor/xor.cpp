#include<bits/stdc++.h>
using namespace std;
int dis[500001],t[500001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ok1=1,ok2=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        if(t[i]!=1)ok1=0;
        if(t[i]>1)ok2=0;
        dis[i]=dis[i-1]^t[i];
    }
    if(ok2||ok1){
        if(k==0){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(t[i]==0)cnt++;
            }
            for(int i=1;i<=n;i++){
                if(t[i]==1&&t[i-1]==1){
                    t[i]=t[i-1]=0;
                    cnt++;
                }
            }
            cout<<cnt;
        }
        if(k==1){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(t[i]==1)cnt++;
            }
            cout<<cnt;
        }
    }
    return 0;
}
