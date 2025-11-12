#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5000];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==3){
        sort(a,a+n);
        if(a[1]+a[2]>a[3]){
            cout<<1<<endl;
            return 0;
        }
    }
    return 0;
}
