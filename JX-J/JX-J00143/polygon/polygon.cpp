#include<bits/stdc++.h>
using namespace std;
int n,a[5005],re=0;
bool aa[5005]={};
void dfs(int ii,int ma){
    if(ii==n+1){
        int s=0;
        for(int i=1;i<=n;i++){
            if(aa[i]) s+=a[i];
        }
        if(s>ma*2) re++;
        return;
    }
    aa[ii]=0;
    dfs(ii+1,ma);
    aa[ii]=1;
    if(a[ii]>ma) ma=a[ii];
    dfs(ii+1,ma);

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,-0x7fffffff);
    cout<<re;
    return 0;
}

