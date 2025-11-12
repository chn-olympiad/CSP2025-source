#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
long long c=0;
bool p=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            p=1;
            break;
        }
    }
    if(p){
        for(int i=1;i<=n-2;i++){
            for(int j=i+2;j<=n;j++)
            {
                cout<<i<<" "<<j<<" "<<b[j]-b[i-1]<<endl;
                if(2*a[j]<b[j]-b[i-1])c++;
            }
        }
        cout<<c%998244353;
    }
    else
    {
        cout<<(n-1)*(n-2)/2%998244353;
    }
}
