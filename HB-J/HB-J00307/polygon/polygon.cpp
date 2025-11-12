#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,num=0;
    long long sum;
    cin>>n;
    int a[5000];
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        if(sum>=2*a[i+1]){
             num++;

        }

    }
    cout<<num+1;
    return 0;
}
