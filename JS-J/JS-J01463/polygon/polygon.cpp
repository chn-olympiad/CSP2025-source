#include<bits/stdc++.h>
using namespace std;

int mx[5010];// yi di i wei zuo wei zui da zhi de pai lie shu liang
int a[5010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]+a[j]>a[j+1]){
                if(mx[j+1]==0){
                    mx[j+1]+=mx[j]%998244353;
                    mx[j+1]+=mx[i]%998244353;
                }

                mx[j+1]+=1%998244353;
                mx[j+1]+=int(pow(2,(j-2)) -1)%998244353;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        cout<<a[i]<<": "<<mx[i]<<endl;
        cnt+=mx[i];
    }
    cout<<cnt;
    return 0;
}
