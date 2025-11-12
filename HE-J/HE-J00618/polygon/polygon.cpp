#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon,out","w",stdout);
    int n,ans=0;
    scanf("%d",&n);
    const int N=n;
    long long a[N+5];
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    if(n==3){
        if((a[1]+a[2]>a[3])&&(a[1]+a[3]>a[2])&&(a[2]+a[3]>a[1])){
            cout<<"1"<<endl;
            return 0;
        }
    }
    cout<<"1"<<endl;
    return 0;
}
