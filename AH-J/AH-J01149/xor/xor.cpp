#include<bits/stdc++.h>
using namespace std;
int n,k,g0,g1;
int ans;
long long int a[5000010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[n]==0 && k==0){
        cout<<n<<endl;
    }else if(a[n]==0 && k==1){
        cout<<0<<endl;
    }else if(a[n]==1){
        for(int i=1;i<=n;i++){
            if(a[i]==0 && a[i+1]==1){
                g0=i;
                g1=n-i;
                break;
            }
        }
        if(k==0){
            cout<<g0+g1/2<<endl;
        }else if(k==1){
            cout<<g1<<endl;
        }
    }
    return 0;
}
