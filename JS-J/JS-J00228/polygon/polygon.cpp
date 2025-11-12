#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5010],he,maxn,num;
signed main(){
    freopen("text.in","r",stdin);
    freopen("text.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                he=a[i],maxn=a[k];
                for(int l=j;l<=k;l++){
                    he+=a[l];
                }
                if(he>maxn*2) num++,cout<<i<<" "<<j<<" "<<k<<endl;
                num%=998244353;
            }
        }
    }
    cout<<num;
    return 0;
}
