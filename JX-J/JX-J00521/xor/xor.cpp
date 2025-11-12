#include <bits/stdc++.h>
using namespace std;
int a[300010],n,k,qz[500010],ans,i,j;
    bool vi[300010];
int main(){
    //freopen("","r",stdin);
    //freopen("","w",stdout);

    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a[i];

    }
    if(a[i]==k){
        ans++;
        vi[i]=500010;
        qz[i]=qz[i-1]^a[i];
    }else{
    vi[i]=vi[i-1]+1;
    qz[i]=qz[i-1]^a[i];
    if(i==1){
        qz[i]=a[i];
    }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(qz[j]-qz[i]==k&&vi[j]-vi[i] >0)
                ans++;
            vi[i]=-5;
            vi[j]=-3;
        }
    }
    cout<<ans;
    return 0;
}
