#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            for(int z=j+1;z<=n;z++){
                if(2*a[z]<a[i]+a[j]+a[z])  sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
