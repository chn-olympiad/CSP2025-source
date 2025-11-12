#include<bits/stdc++.h>
using namespace std;
int n,a[500005][20],ans,k,ans1,f=1,x,b[20],a1[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x==k){
            ans++;
            a1[i]=1;
        }
        if(x>1)f=-1;
        int h=0;
        while(x){
            ++h;
            if(i>1)a[i][h]=a[i-1][h]^(x%2);
            else a[i][h]=x%2;
            x/=2;
        }
    }
    int h=0;
    while(k){
        b[++h]=k%2;
        k/=2;
    }
    if(f==1){
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a1[i]==1)continue;
        for(int i1=i-1;i1>=0;i1--){
            if(a1[i1]==1)break;
            int f1=1;
            for(int j=1;j<=20;j++){
                if(a[i1][j]^a[n][j]!=b[j]){
                    f1=0;
                }
            }
            if(f1==1){
                ans++;
                for(int z=i1;z<=n;z++){
                    a1[z]=1;
                }
            }
        }
    }

    cout<<ans;
    return 0;
}
