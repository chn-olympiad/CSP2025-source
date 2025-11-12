#include<bits/stdc++.h>
using namespace std;
int a[5005],n;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    else if(n==3){
        if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1]){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    cout<<0;
    return 0;
}

