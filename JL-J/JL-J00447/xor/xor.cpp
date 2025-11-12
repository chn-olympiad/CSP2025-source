#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    int a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    bool f[500005];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int x=a[i];
            for(int k=i;k<=j;k++){
                x=x^a[k];
            }
            bool f1=true;
            for(int k=i;k<=j;k++){
                if(f[k]==true) {
                    f1=false;
                    break;
                }
            }
            if(f1==false) continue;
            if(x==m||(i==j&&a[i]==m)){
                for(int k=i;k<=j;k++){
                    f[k]=true;
                }
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
