#include<bits/stdc++.h>
using namespace std;

int n,m,ans=0;
int a[5010],b[5010];
int main(){
    freopen("polygon1.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=b[i-1]+a[i];
    sort(a+1,a+1+n);
    for(int i=n;i>=3;i--){
        int sum=0;
        //cout<<a[i]<<' ';
        for(int j=i;j>=1;j--){
            sum+=a[j];
            if(sum>a[i]*2 && j<=i-2){
                ans++;
            }
        }
        //cout<<"\n";
    }
    cout<<ans;

    return 0;
}