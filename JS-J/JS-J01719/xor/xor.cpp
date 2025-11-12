#include <bits/stdc++.h>
using namespace std;
struct str{
int l,r;
};
str a[500001];
int arr[500001],n,mr,sum=0,d=1;
long long k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
            cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        long long b=arr[i];
    if(b==k){
        a[i].l=i;
        a[i].r=i;
        continue;
    }
        for(int j=i+1;j<=n;j++){
            b^=arr[j];
            if(b==k){
                a[i].l=i;
                a[i].r=j;
                break;
            }
        }
    }
    while(d<=n){
            while(d<=n){
            if(a[d].l!=0){
                sum++;
                mr=a[d].r;
                d++;
                break;
        }
        d++;
    }
        while(d<=n&&d<=mr){
            if(a[d].l!=0&&a[d].r<mr){
                mr=a[d].r;
            }
            d++;
        }
    }
    cout<<sum;
    return 0;
}
