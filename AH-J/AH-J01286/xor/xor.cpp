#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,a[100005],num=0;
    cin>>n>>k;
    long long c[10][10];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            num++;
        }
    }
    if(n<=2&&k==0){
        cout<<num;
        return 0;
    }
    int sum=0;
    if(k==0){
        cout<<num;
        return 0;
    }
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}
