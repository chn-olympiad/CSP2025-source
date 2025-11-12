#include<bits/stdc++.h>

using namespace std;

int n,a[5005]{},b[5005]{},max1=-1;
long long ans=0;
void dfs(int strat1,int chose,int num){

    if(chose>=3){
        if(num>2*max1){
            ans++;
        }
    }
    if(chose>n||strat1>n){
        return;
    }

    for(int i=strat1;i<=n;i++){
        b[chose+1]=a[i];
        int max2=max1;
        if(b[chose+1]>max1){
            max1=b[chose+1];
        }
        dfs(i+1,chose+1,num+b[chose+1]);
        max1=max2;
    }
}



int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dfs(1,0,0);
    cout<<ans%998244353;

    return 0;
}

