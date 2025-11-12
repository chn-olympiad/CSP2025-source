#include<bits/stdc++.h>
using namespace std;
long long b[5010],a[5010],cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+n+1);
    a[1]=b[1];
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+b[i];
    }
    int s=0;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            if(a[i]-a[j]>b[i+1]){
                cnt++;
                s=a[i]-a[j];
            }
            if(s==b[j]){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
