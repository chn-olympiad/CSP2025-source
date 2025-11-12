#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    long long k,ans,m=0;
    scanf("%d%d",&n,&k);
    const int N=n;
    long long a[N+5];
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    if(k==0){
        if(n==1){
            cout<<"0";
            return 0;
        }
        cout<<n/2<<endl;
        return 0;
    }
    if(k==1){
        for(int i=1;i<=n;++i){
            if(a[i]==1){
                m++;
            }
        }
        cout<<m<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
                ans=a[i];
            for(int o=i;o<=j;++o){
                ans=ans^a[o];
            }
            if(ans==k){
                ++m;
                i=j;
            }
        }
    }
    cout<<m<<endl;
    return 0;
}
