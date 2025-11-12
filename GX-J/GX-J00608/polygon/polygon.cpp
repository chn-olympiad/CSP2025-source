#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,s=0;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int x=j;x<=n;x++){
                int b=max(a[i],max(a[j],a[x]));
                if(a[i]+a[j]+a[x]>b*2) s++;
            }
        }
    }
    cout<<s;
    return 0;
}
