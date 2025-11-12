#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+5];
    int sum=0;
    int s[n+5]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            if((s[i]-s[j-1])>a[i]*2) sum++;
        }
    }
    cout<<2*sum-1<<endl;
    return 0;
}
